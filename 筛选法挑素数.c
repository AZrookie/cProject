#include <stdio.h>
#include <stdlib.h>

void screen_procedure (int init[]);

int main(int argc, char *argv[]) {
int init[130],i,number=100;
	for(i=0;i<number;i++){
		init[i]=i+1;
	}
 screen_procedure(init);
	return 0;
}


void screen_procedure (int init []){
	
	int number=100;
	int a[130];
	int flag=0;
	int j=0,i,i1;
	for(i=2;i<number;i++){
		if(isprime(i)>0){
			a[j]=i;
			j++;
			flag++;
			for(i1=i+1;i1<number;i1++){
				if(init[i1]%i==0){
					init[i1]=init[i1+1];
				}
			}
		}
	}
for(i=0;i<flag;i++){
	printf("%d ",a[i]);
}
}
 
int isprime(int a){
	int i,j;
	int flag=0;
	for(i=2;i<a;i++){
		if(a%i==0){
			flag++;
			return 0;
		}
	}
	if(flag==0){
		return 1;
	}
	
}
