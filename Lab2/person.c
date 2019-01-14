#include "person.h"

void addPerson(char *newName, Person *f, Person *m)
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
}
void deletePerson(Person *p)
{
    free(p); 
}
void marryPerson(Person *p, Person *sp)
{
    p->spouse = sp;
    sp->spouse = p; 
}
void divorcePerson(Person *wife, Person *husband)
{
    wife->spouse = NULL;
    husband->spouse = NULL; 
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
