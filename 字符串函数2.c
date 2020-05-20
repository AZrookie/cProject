#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[5][20];
	char t[20];
	int i,j;
	for(i=0;i<5;i++){
		gets(str[i]);
	} 
	for(i=0;i<5;i++){
	    for(j=0;j<5-i-1;j++){
	    	if(strcmp(str[j],str[j+1])>0){
	    		strcpy(t,str[j]);
	    		strcpy(str[j],str[j+1]);
	    		strcpy(str[j+1],t);
			}
		}
	}
	
	for(i=0;i<5;i++){
		printf("%s\n",str[i]);
	}
	
	printf("%d",strcmp("Friend","My"));
	return 0;
}
