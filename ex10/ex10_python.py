import sys

# go through each string in argv
# why am I skipping argv[0]?
i = 0
while i < len(sys.argv): 
	print "arg: " + sys.argv[i]
	i += 1
	
# let's make our own array of strings
states = ["California", "Oregon", "Washington", "Texas"]
num_states = 4;
	
i = 0
while i < num_states:  
	print "state " + states[i]
	i += 1
