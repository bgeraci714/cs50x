// recreated from http://www.learn-c.org/en/Linked_lists
// below link is useful for freeing your linked list after you're done
// http://stackoverflow.com/questions/7025328/linkedlist-how-to-free-the-memory-allocated-using-malloc

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

int main (void) 
{
    void printList (node *head);
    void pushLast(node *head, int data);
    void pushFront (node **head, int data);
    int pop(node **head);
    void clearList (node* head);
    
    node *head = NULL;
    head = malloc(sizeof(node));
    if (head == NULL) {
        return 1; //couldn't allocate the space we needed/wanted
    }
    head->value = 1;
    head->next = malloc(sizeof(node));
    head->next->value = 2;
    head->next->next = NULL;
    
    for (int i = 3; i < 10; ++i)
        pushLast(head, i);
        
    pushFront(&head, 12);
    
    pop(&head);
    
    
    printList(head);
    
    clearList (head);
    
    printList(head);
    
    return 0;
}

void printList (node *head) 
{
    node *current = head;
    
    while (current != NULL) {
        printf("%i\n", current->value);
        current = current->next;
    }
}

// pushes new node to the end of the list
void pushLast(node *head, int data)
{
    node* current = head;
    
    // get current pointing to the last node in the list (NULL is the tail)
    while (current->next != NULL) {
        current = current->next;
    }
    
    // now  we can add a new node
    current->next = malloc(sizeof(node));
    current->next->value = data;
    current->next->next = NULL;
}

void pushFront (node **head, int data) 
{
    // creates the new item and sets its value
    node *newNode;
    newNode = malloc(sizeof(node));
    newNode->value = data;
    
    // links the new item by pointing it to what the head was pointing to
    newNode->next = *head;
    
    // sets the new node as the new head;
    *head = newNode;
    
}

// removes and returns the first item in the list
int pop(node **head) 
{
    int returnValue = -1;
    node *nextNode = NULL;
    
    // if the head points to nothing
    if (*head == NULL) {
        return -1;
    }
    
    // gets the value from the node the head points to and saves it
    nextNode = (*head)->next;
    returnValue = (*head)->value;
    
    free(*head);
    
    // sets the head to be the next node that was saved here
    *head = nextNode;
    
    return returnValue;
}

void clearList (node* head)
{
    node* curr = NULL; 
    
    while ((curr = head) != NULL) { // set curr to head, stop if list empty.
        head = head->next;          // advance head to next element.
        free (curr);                // delete saved pointer.
    }
}