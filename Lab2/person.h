#ifndef PERSON_H
#define PERSON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Structure to hold the family tree */
typedef struct _person
{
    char *name;
    struct _person *father;
    struct _person *mother;
    struct _person *spouse;
} Person;

Person *addPerson(char *newName, Person *f, Person *m);
void deletePerson(Person *p);
void marryPerson(Person *p, Person *sp);
void divorcePerson(Person *wife, Person *husband);

#endif //PERSON_H
