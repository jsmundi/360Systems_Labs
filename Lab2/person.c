#include "person.h"

Person* addPerson(char *newName, Person *f, Person *m)
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

int main()
{
    Person* J = addPerson("John", NULL, NULL);
    Person* M = addPerson("Marry", NULL, NULL);
    marryPerson(J, M);
    divorcePerson(J,M);
    deletePerson(J);
    deletePerson(M);
    return 0;
}
