#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
FILE *fp;
fp=fopen("D:\ceshi.txt","w"); 
int number=2019051058;
char name[9]={"ÐìÔóãü"};
char gender[3]={"ÄÐ"};
fprintf(fp,"%d\n%s\n%s\n",number,name,gender);
      fclose(fp);

 
 
 FILE *fp1;
 fp1=fopen("D:\ceshi.txt","r");
 int i,j;
 	fscanf(fp1,"%d",&j);
 	printf("%d",j);
 int j1,i2,j2;
 	char name1[9];
for (i2=0;i2<9;i2++){
	fscanf(fp1,"%c",&name1[i2]);
	printf("%c",name1[i2]);
}
 char gender1[]={};
for (j2=0;j2<3;j2++){
	fscanf(fp1,"%c",&gender1[j2]);
	printf("%c",gender1[j2]);
}
   
 	return 0;
}
