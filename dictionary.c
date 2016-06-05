// need to create a global pointer for the data structure so that it can be accessed by each function
// without passing the data structure itself as an argument 

// The structure will need to be in the heap so it can exist 
// past the call to each of these functions. 

// This, however, shouldn't be too difficult using malloc. 
// I'll likely want to create an int pointer that stores the 
// number of words added to make Size a piece of cake. 

/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
// passed just the word as an array of chars/string 
// need to access the dictionary using a global pointer 
// because it is not passed as an argument. 

/**
 * The general method for check will be: 
 * 1. get word 
 * 1. make the word lowercase (but don't lose your 's!!!)
 * 2. create prospective location of the word using hash function
 * 3. search the linked list at hashtable[index_of_word]
 * 4. if it's found, return true 
 * 5. else, return false. 
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 // passed a string that represents the file extension to the dictionary file. 
 
 // loading in a nutshell
 // declare infrastructure for hashtable and linked list 
 // hashtable = array of head nodes that point to NULL until added to
 // this should lower the amount of space necessary for the hashtable itself 
 // the biggest concern is going to be the possibility of seg faulting 
 // by creating an unnecessarily large array. 
 // 1000 * char [46] + node* head vs 1000 * node *head. 
 
 /**
  * 1. create file pointer
  * 2. read in words one word at a time
  * 3. pass the word to the hash function
  * 4. get back an index 
  * 5. create linked list node 
  * 6. append node to linked list at given index location
  * 6.1 increment a word counter 
  * 6.2 make sure the end of the last node is set to null
  * 7. move on to the next word 
 */
bool load(const char* dictionary)
{
    // TODO
    return false;
}

// should just be a quick return of an int that was incremented every time
// a word was added to the hash table. 
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */

unsigned int size(void)
{
    // TODO
    return 0;
}

// this one could be really easy and straightforward depending on how I implement it. 
// free the linked lists, then free the arrays the table as a whole? 

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
