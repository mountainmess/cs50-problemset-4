// include libraries
#include <stdio.h>
#include <stdlib.h>

// insert typedef for linked list nodes
typedef struct node
{
    char letter;
    struct node *next;
}
node;


// include function prototypes
    // add node function
void create_node(char user_input);
    // print node list function
void print_list();
void freemem();

node *head = NULL;

//main
int main(void)
{
    // prompt user for number of nodes needed
    //use count variable
    int count;
    printf("how many nodes do you need? \n");
    scanf("%d", &count);

    //prompt user for data to enter into nodes
    // loop 'count' times
    for(int i = 0; i < count; i++)
    {
        char data;
        printf("Enter the letter for node %i: ", i + 1);
        scanf(" %c", &data);
        // take the user input and send to add node function
        create_node(data);
    }
    //print node list function
    print_list();
    freemem();
    return 0;
}

// create node functiuon
void create_node(char user_input)
{
    // allocate space using malloc and create a node
    node *new_node = malloc(sizeof(node));
    // check against NULL
    if (new_node != NULL)
    {
        // add the user inputted data
        new_node->letter = user_input;
        // point it to the original first node
        new_node->next = head;
        //point the head to the new node
        head = new_node;
    }
    else
    {
        // if NULL then free the node and
        freemem();
    }
}


//create print function
void print_list()
{
    node *tmp = head;

    printf("\nI shall now present to you, your list:\n [HEAD] =>");
    while (tmp != NULL)
    {
        printf(" %c.",tmp->letter);
        tmp = tmp->next;
    }
    printf(" => [NULL]\n");


}
//takes no input
// create a temporary pointer node and copy head to pointer
//start printing each node, moving the pointer to the next node afterwards.
// stop when NULL is reached.

//free memory using a null pointer
void freemem()
{

    while (head != NULL)
    {
        node *ptr = head->next;
        free(head);
        head = ptr;
        exit(0);
    }
}
// use a loop to keep going through listt until null is reached
// create a temp node and point to the next pojnter
// delte the head
// point head to temp




