#include <stdio.h> //Access to errno and perror in void die
#include <assert.h> // assert macro. 
#include <stdlib.h> // NULL macro. Access to size_t used in Dabase_load
#include <errno.h> // integer variable (errno) which indicates errors 
#include <string.h> // strncpy function

// two constants made with #define preprocessor
#define MAX_DATA 512
#define MAX_ROWS 100

// definition of Address struct
struct Address {
    int id;
    int set;
    char name[MAX_DATA]; //name and email can both be up to 512 characters long
    char email[MAX_DATA];
};

// definition of Database struct, which contains a list of Address structs (each called Row)
struct Database {
    struct Address rows[MAX_ROWS]; // database can have up to 100 rows (each a Address struct)
};

// Connection struct
struct Connection {
    FILE *file; //pointer to file object
    struct Database *db; //pointer to Database struct
};

// die function definition. prints out error number (if errno) or prints string
void die(const char *message) //kills the program if anything is wrong. Creates ,message string
{
    if(errno) { //errno defined in #include <errno.h>. Returned by system calls 
        perror(message); // prints the interpreted value of the error
    } else {
        printf("ERROR: %s\n", message); // displays message
    }

    exit(1);
}

// Function definition. Takes addr as parameter (which is a Address struct type)
void Address_print(struct Address *addr) 
{
    printf("%d %s %s\n",
        addr->id, addr->name, addr->email); // nested struct pointers.
}

// Function definition. Takes conn as a parameter (Connection struct type)
void Database_load(struct Connection *conn)
{
    // rc is a stream of data (from database)
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to load database."); // Runs die if rc not present
}

// Requests large amount of memory from heap
// Hard to understand this struct but it's apparantly explained later in the course
// Seems to create a Database_open struct which is of a type Connection
struct Connection *Database_open(const char *filename, char mode)
{
    // pointer to conn which is allocated size of Connection struct 
    // Connection struct is the file and db (pointer to database)
    // Struct nested within itself?
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error"); // dies if not enoug memory

    conn->db = malloc(sizeof(struct Database)); //nested struct pointer to database
    if(!conn->db) die("Memory error"); // Another memory error. 

    if(mode == 'c') {
        conn->file = fopen(filename, "w"); // write mode (wipes file)
    } else {
        conn->file = fopen(filename, "r+"); // read and write

        if(conn->file) {
            Database_load(conn); // loads database
        }
    }

    if(!conn->file) die("Failed to open the file"); // dies if file not loaded

    return conn;
}

// Function definition to close database
// Accepts Connection struct (as conn)
void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file); // checks if file exists before closing
        if(conn->db) free(conn->db); // checks if database exists before closing
        free(conn); // frees up the memory allocated by malloc
    }
}

// Function definition. Accepts Connection struct (as conn)
void Database_write(struct Connection *conn)
{
    rewind(conn->file); // sets file position to beginning of stream

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc !=1) die("Failed to write database.");

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first"); // Checks if record already exists at that ID

    addr->set = 1; // Sets that ID point to 1
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    if(!res) die("Name copy failed");

    res = strncpy(addr->email, email, MAX_DATA);
    if(!res) die("Email copy failed");

}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];


    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);

        }
    }
}

int main(int argc, char *argv[])
{
	printf("Starting");
    if(argc < 3) die("USAGE: ex17 <dbfile> <action [action params]>");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if(argc > 3) id = atoi(argv[3]);
    if(id >= MAX_ROWS) die("There's not that many records.");

    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if(argc !=4) die("Need an id to get");

            Database_get(conn, id);
            break;

        case 's':
            printf("Running case s\n");

            if(argc != 6) die("Need id, name, email to set");

            printf("ID is: %d\n",id);

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
    }

    Database_close(conn);

    return 0;
}
