#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mersenne_number () {
	int n,i,j,flag=0,t;
	scanf("%d",&n);
	if(n==1){
		printf("None");
	}
	for(i=2;i<=n;i++){           
		t=pow(2,i)-1;
		flag=0;
		for(j=2;j<t;j++){   
			if(t%j==0){
				flag++;
				break;
			}
		}
        if(flag==0){
        	printf("%d\n",t);
		}	
	}
}

	 
