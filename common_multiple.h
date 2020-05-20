#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int common_multiple (int a,int c) {
int b=0,min=0,n=0,t=0,x=0,d=0,M;
    if (a<c){
    	t=a;
    	a=c;
    	c=t;
	} 
	
	b=c;
   	d=a;
   while (d%b!=0){
  
	    t=d%b;
   	 d=b;
   	 b=t;
   } 
   min=b;

   
   x=a*c;
   if(abs(x/min)>=a&&abs(x/min)>=b){
   	     M=x/min;
   }
	else {
		M=x;
	}
	printf("最小公倍数=%d 最大公约数=%d",min,M);
	return 0;
}
//输入两个数，会输出两数的最大公倍数和最小公约数。
