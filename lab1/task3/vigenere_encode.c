#include <stdio.h>
#include <windows.h>
int main(int argc,char *argv[]){
  /* alphabet */
char re[26][26];
/* loop var */
int i,j,k;
/* the PlainText */
//char str[100]="Welcome rentao11612717 to the C and C++ world";
char str[100];
fgets(str,100,stdin);
printf("%s\n",str);
/* the key */
char key[8]={'V','I','G','E','N','E','R','E'};
//printf("input sentence to encode:\n");
//gets(str);
printf("PlainText: %s \n",str);
/* generate alphabet matrix */
for(i=0;i<26;i++)
{
    for(j=0;j<26;j++)
    {
    k=(int)('A'+i+j);
    k=k>90?k-26:k;
    re[i][j]=(char)k;
    }
}
/* Re is the matrix */
printf("Vigenere encode results:\n");

/* Enc:encoded int */
/* Kec:Key int */
/* seg:PlainText int */
int enc,kec,seg;
int ki=0;
for(i=0;i<strlen(str);i++)
{
  seg=(int)str[i];
  /* encode only for alphabet */
  if((seg>64 && seg<91)||(seg>96 && seg<123))
  {
  kec=(int)key[ki];
  /* Every alphabet is upper! It means some alphabet and 11011111 */
  enc=seg&223;
/*
  //Test output
  printf("%c ",str[i]);
  printf("%d ",enc);
  printf("%d ",kec);
  printf("%c ",enc);
  printf("%c ",kec);
  */
  /* For the matrix */
  enc=enc-65;
  kec=kec-65;
  /* encode in one line :) */
  printf("%c",re[enc][kec]);
  /* Change the key alphabet */
  ki=++ki>7?ki-8:ki;
}else{
  /* print 'un-alphabet' */
  printf("%c",seg);
}
}
printf("\n");

system("pause");
return 0;
}
