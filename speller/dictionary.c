// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#include <strings.h>

//count words
int word_count = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // create a cursor node that points to the words hash function and related linked list
    node *cursor = table[hash(word)];
    //loop to search throughthe list until end reached
    while (cursor != NULL)
    {
        int check = strcasecmp(word, cursor->word);
        if (check == 0) //this means the word is in the dictionary
        {
            return true;
        }
        else //move onto next node
        {
            cursor = cursor->next;
        }

    }
    // hash the word to obtain hash value
    //access linked list at that index in the hash table

    //traverse linked list, looking for the word (strcasecmp)
    //cursor = cursor->next
    //return true if the word is in the dictionary
    //otherwise return false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Source: djib2 by Dan Bernstein (http://www.cse.yorku.ca/~oz/hash.html)
    // adapted for speller by SocratesSatisfied (https://www.reddit.com/r/cs50/comments/eo4zro/good_hash_function_for_speller/)
    unsigned long hash = 5381;
    int c = *word;
    c = tolower(c);
    while (*word != 0)
    {
        hash = ((hash << 5) + hash) + c;
        c = *word++;
        c = tolower(c);
    }
    return hash % N;
}



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open the file
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        printf("error reading file. please try again");
        return false;
    }
    //create a loop
    char temp_word[LENGTH + 1];

    while (fscanf(file, "%s", temp_word) != EOF)
    {
        // allocate space using malloc and create a node
        node *new_node = malloc(sizeof(node));
        // check against NULL
        if (new_node != NULL)
        {
            // add the user inputted data
            strcpy(new_node->word, temp_word);

            // point it to the original first node of the correct hash
            new_node->next = table[hash(temp_word)];
            //point the head to the new node
            table[hash(temp_word)] = new_node;
            word_count++;
        }
        else
        {
            //close program
            return false;
        }
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count != 0)
    {
        return word_count;
    }
    else
    {
        return 0;
    }

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *ptr = table[i]->next;
            free(table[i]);
            table[i] = ptr;
            i++;
        }
    }
    return true;

}
