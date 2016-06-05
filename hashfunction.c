#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 20

int hash_function(char* key)
{
    int hash = 0;
    for(char* ptr = key; *ptr != '\0'; ptr++)
        hash += toupper(*ptr) - 'A';
        
    return hash % SIZE;
}

typedef struct {
    char value[50]; 
} table;

int main(int argc, char* argv[])
{
    void copyString (char *to, char *from);
    table hashtable[SIZE];
    
    for (int i = 0; i < SIZE; i++) 
        hashtable[i].value[0] = '0';
    
    for (int i = 0; i < 5; i++) {
        // get key
        printf("Key: ");
        char* key = GetString();

        // calculate and print index
        printf("The string '%s' will be mapped to index %i\n", key, hash_function(key));
    
        copyString(hashtable[hash_function(key)].value, key);
    }
    for (int i = 0; i < SIZE; i++) 
        if ( ((int) hashtable[i].value[0]) != '0')
            printf("\"%s\" is in the hashtable at index %i!\n", hashtable[i].value, i);

    return 0;
}

void copyString (char *to, char *from)
{
    while (*from) 
        *to++ = *from++;
        
    *to = '\0';
    
}