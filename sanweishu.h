#include <stdio.h>
#include <stdlib.h>
#pragma execution_character_set("ANSI")
void sanweishu() {
	int NUM,i,a,b,c,flag=0;
	scanf("%d",&NUM);
	for(i=100;i<999;i++){
		a=i/100;
		b=i%100/10;
		c=i%100%10;
		if((a*a+b*b+c*c+i/2)==NUM){
			printf("%5d",i);
			flag++;
		}
	} 
	if(flag==0){
		printf("Ã»ÕÒµ½");
	}

}
