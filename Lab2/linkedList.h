#include "person.h"

typedef struct list {
    Person* personPtr; 
    struct list * next;
} list;

void listCompare(list **head1, list **head2);
void push(list **head, Person *p);