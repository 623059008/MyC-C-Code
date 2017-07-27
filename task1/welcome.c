#include <stdio.h>
#include <windows.h>
int main(int argc, char const *argv[])
{

char name[10],id[10];
/* Input Name */
printf("Please enter your Name:");
gets(name);
/* Input Student ID */
printf("Please enter your ID:");
gets(id);
/* Print Welcome sentence */
printf("Welcome %s%s to the C and C++ world\n",name,id);
/* Pause for looking */
system("pause");
return 0;
}
