#include <stdio.h>
#include <stdlib.h>

int sum_prime (int m,int n) {
	int sum=0,number=0,flag=0,i,j;
	for(i=m;i<=n;i++){
		flag=0;
		for(j=2;j<i||i==1;j++){  //当m=1 时，会跳过此条件，flag任为0，因此加上该特殊情况  
			if(i%j==0||i==1){          //素数注意1的特殊情况
				flag++;
				break;	
			}
		}
	    if(flag==0){
	    	sum+=i;
	    	number++;//素数数量  
		}
	}
	printf("%d %d",number,sum);
	
	return 0;
}
//输出两数间的素数和