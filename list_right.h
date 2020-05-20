#include <stdio.h>
#include <stdlib.h>

int list_right(int number,int m) {
	int i,j,i1,t;
	int a[300];      //数组要足够大，否则最后一个答案会数组越界  
	for(i=0;i<number;i++){
		scanf("%d",&a[i]);
	}
	
	m%=number;
		for(i=number+m-1;i>m-1;i--){
			a[i]=a[i-m];    //i=number+m，不是number-1或number，否则最后一个数无法输出。 
		}
		for(i=0;i<=m-1;i++){
			a[i]=a[i+m];
		}
//	for(i=0;i<number+m;i++){
//		printf("%d\n",a[i]);
//	}

	for(i1=0;i1<m;i1++){     //TIP；number+m是一个重要数据，
		a[i1]=a[i1+number];
	}
	printf("%d",a[0]); 
	for(i=1;i<number;i++){
		printf(" %d",a[i]);
	}
	return 0;
}
//输入数组长度和右移位数。
