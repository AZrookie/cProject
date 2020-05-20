#include <stdio.h>
#include <stdlib.h>

int yueshu(int m,int n);

int main(int argc, char *argv[]) {
int m,n,t;
scanf("%d %d",&m,&n);
if(m<n){
	t=m;
	m=n;
	n=t;
}

int x = yueshu(m,n);
printf("%d",x);
	return 0;
}

int yueshu(int m,int n){
	
	if(m%n==0){
		return n;
	}
	else {
		return yueshu(n,m%n);
	}
}
