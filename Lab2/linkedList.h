#include "person.h"

/* Struct to  hold the pointers of person list */
typedef struct list {
    Person* personPtr; 
    struct list * next;
} list;

void listCompare(list **head1, list **head2);
void push(list **head, Person *p);
void destroyLinkedList(list *head_ref);
void print_list(list *head);
