#include "person.h"
#include "linkedList.h"

Person *addPerson(char *newName, Person *f, Person *m)
{

    Person *newP = (Person *)malloc(sizeof(Person));

    newP->name = NULL;
    newP->father = NULL;
    newP->mother = NULL;
    newP->spouse = NULL;

    if (newName != NULL)
    {
        newP->name = newName;
    }
    if (f != NULL)
    {
        newP->father = f;
    }
    if (m != NULL)
    {
        newP->mother = m;
    }

    printf("Successfully added %s \n", newP->name);

    return newP;
}
void deletePerson(Person *p)
{
    free(p);
}
void marryPerson(Person *p, Person *sp)
{
    p->spouse = sp;
    sp->spouse = p;

    printf("Married %s & %s \n", p->name, sp->name);
}
void divorcePerson(Person *wife, Person *husband)
{
    wife->spouse = NULL;
    husband->spouse = NULL;
    printf("Divorced %s & %s \n", wife->name, husband->name);
}

void push(list **head, Person *p) {
    struct list* newnode = malloc(sizeof(struct list));
    newnode->personPtr=p;
    newnode->next=*head;
    *head = newnode; // *head stores the newnode in the head
}

void print_list(list * head) {
    list * current = head;

    while (current != NULL) {
        printf("%s\n", current->personPtr->name);
        current = current->next;
    }
}

void destroyLinkedList(list **head_ref)
{

        struct list* current = *head_ref;
        struct list* next;
        while (current != NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        *head_ref = NULL;

}
void listCompare(list **head1, list **head2)
{
    if(head1 != NULL && head2 !=NULL)
    {

    }
}

int main()
{
    Person *J = addPerson("John", NULL, NULL); //Father
    Person *K = addPerson("Marry", NULL, NULL); //Mother
    Person *L = addPerson("John Jr", J, K); //Kid 1
    Person *M = addPerson("Marry Jr", NULL, NULL); // Kid 2

    marryPerson(J, M);

    list * head = NULL;
    //head = malloc(sizeof(list));
    //if (head == NULL) {
    //    return 1;
    //}
    //head->personPtr = J;
    //head->next = NULL;

    push(&head,K);
    push(&head,M);

    push(&head,L);

    print_list(head);

    destroyLinkedList(&head);
    free(head);
    deletePerson(J);
    deletePerson(K);
    deletePerson(L);
    deletePerson(M);

    return 0;
}
