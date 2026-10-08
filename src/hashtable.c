#include "hashtable.h"

#include <stdlib.h>

#include "hashentry.h"

#include <math.h>

// We want to define a hash table in C, that contains:
//      command: key
//      [suitable parameters, functionality]: value

// As we are in C, we are going to need to do this manually
// So some things we'll need to consider:
// 	Bucket index = value returned by the hash function for a key in a seperate chaining method. Each index in the array is called a bucket and it is a bucket of a linked list
// 	Rehashing = used to reduce collisions as no. elements increase. In rehashing, a new table is created with larger capacity (usually double) and all existing elements are reinstered. This is not relevant for this program as the hash map is a constant, we will not be adding and removing elements
// 	Load factor = no. elements / total no. of buckets
// 	Collision = where bucket index is not empty, means a linked list head is present at the bucket index. We have two or more values that map to the same bucket index

// We will be doing things slightly different to normal, as we will not be using linked lists for buckets
// 	instead, we will be using a key and an array value
// We are not updating the table during runtime, so it is a little easier
//		We have the insert, hash, and search functions

// I have chosen to do a hash table as I thought it would be neater than ifs (e.g. if command == 'ls' else command == 'pwd' etc.)


// Our hash table
struct commandSet {
    int numCommands, capacity;

    // Define our hash table entries
    struct bucket **buckets;
};

// We initialise a hash set that will be used to store commands
void initialiseCommands(struct commandSet *cs) {
    // Default capacity is just 100 for now
    // A bit much, but we need to try and avoid multiple colissions with same key
    cs->capacity = 100;
    cs->numCommands = 0;

    // Our commands
    //      we create an array of buckets in accordance with our capacity
    //      struct bucket* means that we are allocating memory based on the size needed to store one pointer to a bucket, not the bucket itself
    //      we use struct bucket** to make a pointer to a pointer
    //      we do this as cs->buckets will point to the first element of an array of pointers
    cs->buckets = (struct bucket**)malloc(sizeof(struct bucket*) * cs->capacity);

    return;
}

// Our hash function
//      TODO: implement our own hash function. For now we have used a tutorial provided one to begin with
//      TODO: hash function inspired (we just did the sum + changed primeNum and x to be the index**index) from https://www.geeksforgeeks.org/dsa/implementation-of-hash-table-in-c-using-separate-chaining/
int hashf(struct commandSet* cs, char *key) {
    int bucketIndex;
    int sum = 0, x = 1;
    for (int i = 0; i < strlen(key); i++) {
        // sum = sum + (ascii value of char * (x ^ x))
        // where x = 1, 2, 3 ... n and related to the index of the character (but starting from 1)
        // We do sum % capacity a lot to ensure we don't
        sum = ((sum % cs->capacity) + (((int)key[i] + (x ** x)) % cs->capacity) % cs->capacity);

    }
}

