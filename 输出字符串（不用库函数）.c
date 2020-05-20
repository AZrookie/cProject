#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char str[200];
	int i;
	i=0;
	char ch;
	int count=0;
	for(i=0;i<100&&ch!='\n';i++){
		ch=getchar();
		str[i]=ch;
		count++;
	}
	str[i]='\0';//不手动加结束标志的话，就会输出乱码 
	printf("the string length is %d\n",count);
	printf("%s",str);
	return 0;
}
