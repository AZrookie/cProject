#include <stdio.h>
#include <stdlib.h>

void scanArray(int *a,int n);
int max (int*a,int n);
double average(int*a,int n);


int main(int argc, char *argv[]) {
	int n,i;
	scanf("%d",&n);
	 int a[200];
	 scanArray(a,n);
   int x = max(a,n);
   printf("%d",x);
   double m = average(a,n);
   printf("%f",m);
	return 0;
}

void scanArray(int *a,int n){
	int *p;
	for(p=a;p<a+n;p++){
		scanf("%d",p);
	}
	
}

int max (int*a,int n){
	int *p;
	int max = *a;
	for(p=a;p<a+n;p++){
		if(*p>max){
			max=*p;
		}
	}
	
	return max;
}

double average(int *a,int n){
	int *p;
	double sum;
	
	for(p=a;p<a+n;p++){
		sum+=(double)(*p);
	}
	
	double average = sum/(double)n;
	return average;
}

