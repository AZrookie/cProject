#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]){
int a,b;
a=atoi(argv[1]);
b=atoi(argv[3]);

	if (argc!=4){
	   return 1; 
	}

	if(argv[2][0]=='+'){
		printf("%d+%d=%d",a,b,a+b);
         return 0;
	}
	else if(argv[2][0]=='-'){
        printf("%d-%d=%d",a,b,a-b);
         return 0;
	}
	else if(argv[2][0]=='%'){
         printf("%d%%%d=%d",a,b,a%b);
         return 0;
	} 
	else if(argv[2][0]=='/'){
		 double x;
         x=(double)a/(double)b;
         printf("%d/%d=%.2f",a,b,x);
         return 0;
	} 
	else if(argv[2][0]=='*'){
	     long t;
	     t=(long)a*(long)b;
	     printf("%d*%d=%lld",a,b,t);
	     return 0;
	}
	else{
		return 2;
	}
	return 0;
}
