#include<stdio.h>
#include"string.h"
void dele(char arr[]);
int main(void)
{
	char strA[81];
	gets(strA);
	dele(strA);
	puts(strA);
	return 0;
}

void dele(char arr[]){
int n = strlen(arr);
int i,j;
int len = 0,count=0;
char t;
for(i=0;i<n-1;i++){
	for(j=0;j<n-1-i;j++){
		if(arr[j]>arr[j+1]){
			t=arr[j];
			arr[j]=arr[j+1];
		    arr[j+1]=t;	
		}
	}
}
    for(i=0;i<n-1;i++)
    {
        if ((arr[i] != arr[i+1]))
        {
            arr[len++] = arr[i];
        }
    }
    arr[len++] = arr[n-1];
    for(i=0;i<len;i++){
    	if(arr[i]==' '){
    		count++;
    		for(j=i;j<len-1;j++){
    			arr[j]=arr[j+1];
			}
		}
	}
arr[len-1]='\0';
} 
