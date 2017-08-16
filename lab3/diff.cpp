#include "diff.h"
/*
 * compare
 * doc1,doc2    Two file path
 * return 0  they are different
 * return 1  they are same.
 */
int diff(char *doc1,char *doc2)
{
 FILE *fp1,*fp2;
 if((fp1 = fopen(doc1,"r")) == NULL)
	 {
			 printf("can't open '%s'\n",doc1);
			 fclose(fp1);
	 return 0;
	 }
	 if((fp2 = fopen(doc2,"r")) == NULL)
	 {
			 printf("can't open '%s'\n",doc2);
	 fclose(fp2);
			 return 0;
	 }
	 //先比较大小
	 fseek(fp1,0L,SEEK_END);
	 int size1 = ftell(fp1);
	 fseek(fp2,0L,SEEK_END);
	 int size2 = ftell(fp2);
	 if (size1 != size2)
	 {
		 return 0;
	 }
	 //随机抽取进行对比
	 for (int i = 0; i < 10; i++)
	 {
		 int random = rand() % size1 + 1;
		 fseek(fp1,random,SEEK_SET);
			 fseek(fp2,random,SEEK_SET);
			 for(int k=0;k<10;k++)
			 {
				 char text1 = fgetc(fp1);
				 char text2 = fgetc(fp2);
				 if(text1 != text2)
				 {
					 fclose(fp1);
					 fclose(fp2);
					 return 0;
				 }
		 }
	 }
	 //将两个文件按字节去比较
		for (int l = 0; l < size1; l++)
	 {
		 fseek(fp1,l,SEEK_SET);
			 fseek(fp2,l,SEEK_SET);
			 char text1 = fgetc(fp1);
			 char text2 = fgetc(fp2);
			 if(text1 != text2)
			 {
				 fclose(fp1);
				 fclose(fp2);
				 return 0;
			 }

	 }
	 fclose(fp1);
	 fclose(fp2);
	 return 1;
}
