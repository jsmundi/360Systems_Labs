#include <stdio.h>

/* Structure to hold the family tree */

typedef struct _person
{
    char *name;
    struct _person *father;
    struct _person *mother;
    struct _person *spouse;
} Person;

void deletePerson (Person *p);
void marryPerson (Person *p);
void divorcePerson (Person *wife, Person *husband); 
