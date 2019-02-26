#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

//CTRL C is SIGINT

void printType(int sig)
{
     
}

int main(int argc, char const *argv[])
{

    signal(SIGALRM, printType); 
    int j = 0;

    for(int i = 1; i < argc; i++)
    {
        j = 0;

        while(argv[i][j] != '\0')
        { 
            ualarm(300000, 0);
            pause();
            printf("%c",argv[i][j]); 
            fflush(stdout);
            ++j;
        }
    

    }
    printf("\n"); 

    return 0;
}
