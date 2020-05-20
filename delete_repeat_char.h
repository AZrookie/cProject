#include <stdio.h>
#include <stdlib.h>

void delete_repeat_char() {
	char str[2000],str1[200];
	char t;
	int i,j,flag=0,i1=0,len=0;
	gets(str);
	for(i=0;str[i]!='\0';i++){
		len++;
	} 
	
	for(i=0;i<len;i++){
		    flag=0;
		for(j=0;j<i;j++){
			
			if(str[i]==str[j]){//对str[i]之前的字符判断，若重复，flag=1 
				flag=1;
			}
		}
	        if(flag==0){
		    	str1[i1]=str[i];//若没有重复字符，赋值给新的数组 
		    	i1++;//i1不能放在式子上面，否则输入直接其实值为str1[1]; 
			}
	}


for(i=0;i<i1-1;i++){
	for(j=0;j<i1-i-1;j++){//冒泡排序 
		if(str1[j]>str1[j+1]){
			t=str1[j];
			str1[j]=str1[j+1];
			str1[j+1]=t;
		}
	}
}

for(i=0;i<i1;i++){
	printf("%c",str1[i]);
}
}
