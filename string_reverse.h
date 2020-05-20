#include <stdio.h>
#include <stdlib.h>
void reverse(){
    int i=0,j,len=0;
	char a[100];
	 gets(a); 
	while(a[i]!=0){
		len++;
		i++;
	}
for(j=len-1;j>=0;j--){
	printf("%c",a[j]);
}

} 
