#include "person.h"
#include "linkedList.h"

/* Create a new person by setting all the defaults to NULL.
   Allocate memory for the struct and append new values given
   the values are passed in as non-null values
*/
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

/*Free the memory for person struct*/
void deletePerson(Person *p)
{
    free(p);
}

/* Marry two people, update the spouse pointers pointing to each other*/
void marryPerson(Person *p, Person *sp)
{
    p->spouse = sp;
    sp->spouse = p;

    printf("Married %s & %s \n", p->name, sp->name);
}

/* Divorce two people, clear the spouse data and set to Null */
void divorcePerson(Person *wife, Person *husband)
{
    wife->spouse = NULL;
    husband->spouse = NULL;
    printf("Divorced %s & %s \n", wife->name, husband->name);
}

/* Push the Person pointer onto the linked list provided header pointer.
   No need to update the header pointer since doubple pointer is implemented.
*/
void push(list **head, Person *p)
{
    struct list *newnode = malloc(sizeof(struct list));
    newnode->personPtr = p;
    newnode->next = *head;
    *head = newnode; // *head stores the newnode in the head
}

/* Prints the linked list given header pointer */
void print_list(list *head)
{
    list *current = head;

    while (current != NULL)
    {
        printf("%s\n", current->personPtr->name);
        printf("Father %s\n", current->personPtr->father->name);

        current = current->next;
    }
}

/*
    Destroys the linked list. Header pointer is passed
    in loops through the linked list destroying each
    node individually to insure no memory leaks.
*/
void destroyLinkedList(list **head_ref)
{

    struct list *current = *head_ref;
    struct list *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

/* Compare the list structure using string compare for two different 
   linked list given the headers for both lists. 
*/
void listCompare(list **head1, list **head2)
{
    list *curr1 = *head1;
    list *curr2 = *head2;
    int flag = 0;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->personPtr->father != NULL && curr2->personPtr->father != NULL)
        {
            flag = strcmp(curr1->personPtr->father->name, curr2->personPtr->father->name);
        }
        if (curr1->personPtr->mother != NULL && curr2->personPtr->mother != NULL)
        {
            flag = strcmp(curr1->personPtr->mother->name, curr2->personPtr->mother->name);
        }
        if (curr1->personPtr->name != NULL && curr2->personPtr->name != NULL)
        {
            flag = strcmp(curr1->personPtr->name, curr2->personPtr->name);
        }
        if (curr1->personPtr->spouse != NULL && curr2->personPtr->spouse != NULL)
        {
            flag = strcmp(curr1->personPtr->spouse->name, curr2->personPtr->spouse->name);
        }

        curr1 = curr1->next;
        curr2 = curr2->next;

        if (flag != 0)
        {
            printf("Strings do not match\n");
            break;
        }
    }

    if (flag == 0)
    {
        printf("Strings Match\n");
    }
}

int main()
{
    //Create new people
    Person *J = addPerson("John", NULL, NULL);     //Father
    Person *K = addPerson("Marry", NULL, NULL);    //Mother
    Person *L = addPerson("John Jr", J, K);        //Kid 1
    Person *M = addPerson("Marry Jr", NULL, NULL); // Kid 2

    //Marry divorce people
    marryPerson(J, M);

    //Header pointer for linked list
    list *head = NULL;
    list *head2 = NULL;

    //Push the people to new linked list
    push(&head, K);
    push(&head, M);
    push(&head, L);

    push(&head2, K);
    push(&head2, M);
    push(&head2, L);

    listCompare(&head, &head2);

    print_list(head);

    //Free the linked list
    destroyLinkedList(&head);

    //Free the head for linked list
    free(head);

    //Delete all the persons
    deletePerson(J);
    deletePerson(K);
    deletePerson(L);
    deletePerson(M);

    return 0;
}
