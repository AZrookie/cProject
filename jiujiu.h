#include <stdio.h>
#include <stdlib.h>


void jiujiu() {
   int n,i,j;
   printf("����һ���������������������Ϊֹ�ľžų˷���\n");
   scanf("%d",&n);
     for(i=1;i<=n;i++){
     	for(j=1;j<=i;j++)
     	   printf("%d*%d=%-3d",i,j,j*i);
			printf("\n"); //����	
	 }
}
