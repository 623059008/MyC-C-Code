#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"


int main(int argc, char *argv[])
{
    int index;
    char ch;
    while((ch = getopt(argc, argv, "dt:")) != EOF)
    {
        switch(ch)
        {
            case 'd':
                //puts("enter d");
                break;
            case 't':
                puts("enter t");
                //printf("optarg value is %s\n", optarg);
                break;
            default:
                return 1;
        }
    }
    printf("%s\n",optind );
    argc -= optind;
    argv += optind;


    for(index = 0; index < argc; index++)
    {
        puts(argv[index]);
    }


    return 0;
}
