#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int number[3][3];
int i,j,x=0,x1=0,x2=0,o=0,o1=0,o2=0;
for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		scanf("%d",&number[i][j]);     //¾®×ÖÆå¸³Öµ 
	}
}

for(i=0;i<3;i++){
	x=0,x1=0,o=0,o1=0; 
	for(j=0;j<3;j++){
		if(number[i][j]==-1){
		   x++;}
		else                 //ÅÐ¶ÏÐÐ 
		   o++;
		   
		   
		if(number[j][i]==-1){
			x1++;
		}                   //ÅÐ¶ÏÁÐ 
	    else 
	        o1++;
	}
}
if (x==3||x1==3){
	printf("xÓ®");
}
else if(o==3||o1==3){
	printf("oÓ®");
}

for(i=0;i<3;i++){
	x2=0,o2=0;
	for(j=0;j<3;j++){
		if(number[i][i]==-1||number[i][2-i]==-1){
			x2++;
		}
		else if(number[i][i]==0||number[i][2-i]==0){
			o2++;
		}
		        
	}
}
if(x2==3){
	printf("xÓ®");
}
if(o2==3){
	printf("oÓ®");
}
return 0;
}
