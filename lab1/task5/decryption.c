#include <stdio.h>
int main(int argc, char const *argv[]) {
  /* alphabet */
char re[26][26];
/* loop var */
int i,j,k;
/* the PlainText */
//char str[100]="Welcome rentao11612717 to the C and C++ world";
printf("Please enter what you want to decode by Vigenere:\n");
char str[100];
fgets(str,100,stdin);
//printf("%s\n",str);
/* the key */
char key[8]={'V','I','G','E','N','E','R','E'};
//printf("input sentence to encode:\n");
//gets(str);
printf("PlainText:\n%s \n",str);
printf("Vigenere encode results:\n");

/* enc:EncodedText int */
/* kec:Key int */
/* seg:EncodedText int */
int enc,kec,seg;
int ki=0;
for(i=0;i<strlen(str);i++)
{
  seg=(int)str[i];
  /* encode only for alphabet */
  if((seg>64 && seg<91)||(seg>96 && seg<123))
  {
  kec=(int)key[ki];
  /* For the matrix */
  enc=seg;
  printf("%c",(char)(((enc-kec<0)?(enc-kec+26):(enc-kec))+65));
  /* Change the key alphabet */
  ki=++ki>7?ki-8:ki;
}else{
  /* print 'un-alphabet' */
  printf("%c",seg);
}
}
//system("pause");
  return 0;
}
