#include "hashentry.h"

// Hash-table value
// This is our commands functionality, two parameters
//      a pointer to the function which runs the command
//      a list of valid parameters that are used to verify no invalid parameter is given
struct command {
    // The name of the command, a string of max 6 characters (we do 7 as we have to account for '\0')
    // char commandName[7];

    // A pointer to a function defining the command's functionality
    // We take in number of arguments/parameters, and the arguments/parameters, similar to main with command-line args
    // 	TODO: we are inevitably going to run into problems when we implement the pipeline stuff, but leave as void return type for now
    void (*fptr)(int argc, char *argv[]);

    // Array of pointers to strings, contains each parameter that's implemented for a command
    // We must manually define the size of valid Parameters at runtime (for each command)
    // Then free memory!
    char **validParameters;
};

// Hash-table entry
struct bucket {
    // Key is a string, which is the name of our command
    // that way we can search by simply using the hash function on the user's input as it will directly relate to the hash table
    char *key;

    struct command cmd;
};


void setBucket(struct bucket *b, char *k, const struct command cm) {
    b->key = k;
    b->cmd = cm;

    return;
}