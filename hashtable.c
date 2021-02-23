#include <stdio.h>
#include <stdlib.h>

// declare the hash functions
int hash_code(char* str);
void insert_data(int hash, char* str);
void search_list(char* key);
void display_list();
void print_list();
// declare the capacity of the hash table
const int CAPACITY = 10;
enum record_status {EMPTY, DELETED, OCCUPIED};

typedef struct Record
{
      char* name;
      enum record_status status;
}Record;

Record hash_table[CAPACITY];
char* str;

int main(void)
{
    printf("hello\n");
    // how many names do you want to store? up to 10
    // ask for n number of names.
    // each time run it through the hash function
    // store the name at the returned number
    // if that number has been used before then check the  next number in line until it can be stored somewhere
    // print the list.
        // prompt user for number of nodes needed
    //use count variable
    int key, option;
      int count = 0;
      for(int i = 0; i < CAPACITY; i++)
      {
            hash_table[i].status = EMPTY;
      }
    do
    {
        printf("how many names do you need to store (up to 10)? \n");
        scanf(" %d", &count);
    }while (count < 1 | count > 10);



    //prompt user for data to enter into nodes
    // loop 'count' times
    for(int i = 0; i < count; i++)
    {
        str = malloc(sizeof(str));
        printf("Enter the name for record %i: ", i + 1);
        scanf(" %s", str);
        insert_data(hash_code(str), str);
    }
    print_list();

    return 0;
}

int hash_code(char* data)
{
    int sum = 0;
    for (int j = 0; data[j] != '\0'; j++)
    {
        sum += data[j];
    }
    return sum % CAPACITY;
}

void insert_data(int hash, char data[sizeof(str)])
{
    int position, temp;
    temp = hash;
    position = temp;
    for(int i = 0; i != CAPACITY; i++)
    {
        if (hash_table[position].status == EMPTY || hash_table[position].status == DELETED)
        {
            hash_table[position].name = data;
            hash_table[position].status = OCCUPIED;
            printf("Record inserted\n");
            return;
        }
        position = (i + temp) % CAPACITY;

    }
}

void display_list()
{

}

void delete_data()
{

}

void search_list(char* key)
{
    // get the hash code
    int temp = hash_code(key);
}

void print_list()
{
    printf("\n This is your hash table \n");
    for (int i = 0; i < CAPACITY; i++)
    {
        printf("[%d]: ", i + 1);
        if(hash_table[i].status == OCCUPIED)
        {
            printf(" %s\n", hash_table[i].name);
            free(hash_table[i]);
        }
        else
        {
            printf("Empty\n");
            free(hash_table[i]);
        }
    }
    return;
}

