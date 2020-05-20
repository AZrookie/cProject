#include <stdio.h>
#include <stdlib.h>


void jiujiu() {
   int n,i,j;
   printf("输入一个数，程序会输出到这个数为止的九九乘法表\n");
   scanf("%d",&n);
     for(i=1;i<=n;i++){
     	for(j=1;j<=i;j++)
     	   printf("%d*%d=%-3d",i,j,j*i);
			printf("\n"); //空行	
	 }
}
