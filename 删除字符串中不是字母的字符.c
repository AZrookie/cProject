#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteString(char *a,char str[15]);

int main(int argc, char *argv[]) {
char str[15];
gets(str); 
deleteString(str,str);
	return 0;
}

void deleteString(char *a,char str[15]){
	char *p;
	char *p1;
	int len=0;
	for(p=a;p<a+strlen(str);p++){
		if(!(65<=*p&&*p<=90||97<=*p&&*p<=122)){
		          for(p1=p;*p1!='\0';p1++){
		          	*p1=*(p1+1);
		          	 p--;
				  }
		   }
		      
	}
	
	for(p=a;p<a+strlen(str);p++){
		printf("%c",*p);
	}
}

