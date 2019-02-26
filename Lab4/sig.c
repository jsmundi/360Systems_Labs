#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

//CTRL C is SIGINT

void parent(int sig)
{
    printf("Parent...\n");
}

void child(int sig)
{
    printf("Child...\n");
}
int main(int argc, char const *argv[])
{

    int cpid = 0;

    cpid = fork();

    //Child
    if (cpid == 0)
    {

        signal(SIGINT, child);
    }

    //Parent
    else
    {
        signal(SIGALRM, parent);
        while (1)
        {
            alarm(1);
            pause();
            signal(SIGINT, child);
        }
    }

    return 0;
}
