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
			
			if(str[i]==str[j]){//��str[i]֮ǰ���ַ��жϣ����ظ���flag=1 
				flag=1;
			}
		}
	        if(flag==0){
		    	str1[i1]=str[i];//��û���ظ��ַ�����ֵ���µ����� 
		    	i1++;//i1���ܷ���ʽ�����棬��������ֱ����ʵֵΪstr1[1]; 
			}
	}


for(i=0;i<i1-1;i++){
	for(j=0;j<i1-i-1;j++){//ð������ 
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
