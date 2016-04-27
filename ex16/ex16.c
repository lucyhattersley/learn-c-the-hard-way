// includes the <stdio.h> C Library functions
#include <stdio.h> // most of the useful commands such as printf()
// includes the <assert.h> Library functions
#include <assert.h> // enables use of assert function
// includes the <stdlib.h> Library functions
#include <stdlib.h> // include malloc and free
// includes the <string.h> Library functions
#include <string.h> // includes strdup()

// defines a struct named Person with four variables
struct Person {
    // creates a string variable called name (a pointer to an array of characters)     
    char *name;
    // creates an age integer
    int age;
    // height integer
    int height;
    // weight integer
    int weight;
}; // note the ';' at the end of the struct definition

// this is where shizzle gets real complex
// This is a function used to create an instance of the struct (defined above)
// It allocates the memory to the struct

// I'm not wholly sure why it starts with struct Person rather than void (one for stack exchange
// Next we have a pointer to *Person_create. The brackets indicate values to be set
// The variables inside brackets match the variables inside struct Person
// MAYBE LOOK AT MEMORY ADDRESS OF who->name etc. Compare to address of struct in general.
struct Person *Person_create(char *name, int age, int height, int weight)
{
    // this creates a pointer to *who that is is the size of the struct definition
    struct Person *who = malloc(sizeof(struct Person));
    // checks that Who is not NULL empty
    assert(who != NULL);

    // The -> seems to be like '.' dot notation in objects
    // strdup(name) works like malloc. It assigns memory.
    // This has to be cleared separately from the struct
    // otherwise it causes a memory leak
    who->name = strdup(name); // returns a pointer to a duplicate of string
    // This assings the age variable (passed in from the *Person_create function
    // to the who->age variable
    who->age = age;
    // Assings height from function to internal height variable
    who->height = height;
    // Assigns weight
    who->weight = weight;
    // The ints don't need memory allocating to them. Because
    // they are signed ints that are allocated 4-bits by default 

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight %d\n", who->height);
    printf("\tWeight %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
            "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age +=20;
    frank->weight += 20;
    Person_print(frank);

    Person_destroy(NULL);

    return 0;
}
