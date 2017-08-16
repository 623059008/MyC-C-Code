#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[]) {

  int ch;
  int opterr = 0;
 while ((ch = getopt(argc,argv,"s:i:"))!=-1)
 {
         switch(ch)
         {
                 case 's':
                         printf("option s:'%s'\n",optarg);
                         break;
                 case 'i':
                         printf("option i:%s\n",optarg);
                         break;
                 default:
                         printf("other option :%c\n",ch);
         }
 }
 printf("optopt +%c\n",optopt);
  return 0;
}
