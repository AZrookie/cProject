#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int n,flag=0,i;
printf("please input numsize(n>4):");
scanf("%d",&n);          //���������С 
printf("n = %d\n",n);
int *password,*pi,*towards;
password=(int *)malloc(sizeof(int)*n);    //ָ��ָ�򿪱ٵ�n���ռ���׸�Ԫ�ص�ַ 
printf("please input %d numbers:",n);
for(towards=password;towards<password+n;towards++){
	scanf("%d",towards);                          //��������Ԫ�ظ�ֵ 
}

for(towards=password,i=1;towards<password+n;towards++,i++){         //��������ÿ��Ԫ�� 
	for(pi=password+i;pi<password+n;pi++){         
		if(*towards==*pi){
			flag++;                //ÿ��piֻҪ����֮���Ԫ�رȽϾͿ��ԣ�����pi���������бȽϣ��϶�flag��=0 
			break;   
		}
	}
}
if(flag==0){
	printf("true");
}
else if(flag!=0){
	printf("false");
}
	return 0;
}
