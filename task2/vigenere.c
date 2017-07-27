#include <stdio.h>
int main(int argc, char const *argv[]) {
  /* alphabet */
char re[26][26];
  /* loop var */
int i,j,k;
for(i=0;i<26;i++)
{
for(j=0;j<26;j++)
{
k=(int)('A'+i+j);
/* substract the extra number */
k=k>90?k-26:k;
/* store in char array */
re[i][j]=(char)k;
/* print every line */
printf("%c ",re[i][j]);
}
/* print an Enter */
printf("\n");
}
return 0;
}
