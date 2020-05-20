#include <stdio.h>
#include <stdlib.h>

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