#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int n,flag=0,i;
printf("please input numsize(n>4):");
scanf("%d",&n);          //输入数组大小 
printf("n = %d\n",n);
int *password,*pi,*towards;
password=(int *)malloc(sizeof(int)*n);    //指针指向开辟的n个空间的首个元素地址 
printf("please input %d numbers:",n);
for(towards=password;towards<password+n;towards++){
	scanf("%d",towards);                          //对数组中元素赋值 
}

for(towards=password,i=1;towards<password+n;towards++,i++){         //遍历数组每个元素 
	for(pi=password+i;pi<password+n;pi++){         
		if(*towards==*pi){
			flag++;                //每次pi只要与其之后的元素比较就可以，否则pi会和自身进行比较，肯定flag！=0 
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
