#include <stdio.h>
#include <stdlib.h>

void scanArray(int (*a)[9]);//������ָ�� 

int main(int argc, char *argv[]) {
int a[5][9];
int i,j;
scanArray(a);


	return 0;
}

void scanArray(int (*a)[9]){
	int (*p)[9];
	int j,i;
	for(p=a;p<a+5;p++){
		for(j=0;j<9;j++){
			scanf("%d",*p+j);//��*p+j������p+j����Ϊa[i][j]�൱��a[i]+j,��a[i]=a+i.�����p+j����ôֻ�Ὣÿһ�еĵ�һ���������ȥ 
		}
	}

/*for(i=0;i<5;i++){
	printf("\n");
	for(j=0;j<9;j++){
		printf("%d ",a[i][j]);
	}
}
*/

int max=*a[0];
int max_row,max_col;
 for(p=a,i=0;p<a+5;p++,i++){
 	for(j=0;j<9;j++){
 		if(*(*p+j)>max){
 			max=*(*p+j);
 			max_row=i;
 			max_col=j;
		 }
	 }
 }
 
 printf("%d %d %d",max,max_row,max_col);
} 
