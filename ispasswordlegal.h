#include <stdio.h>
#include <stdlib.h>

void ispasswordlegal()
    {  	
     	int i=0,len=0,j=0;
     	int a[200];
        gets(a);
	   while (a[i]!='\0'){ //ͳ�Ƴ��� 
	   	 i++;
	   	 len++;
	   } 
	    if (len>=6&&len<=15){
	       printf("���볤�Ⱥϸ�Ϊ%d",len);
	         }                              //�жϳ����Ƿ�ϸ� ���ϸ�ִ����һ�����������ϸ���� 
	    else
	      {
		   printf("���볤�Ȳ��ϸ�Ϊ%d",len);
	         }
	
	 int s1=0,z1=0,z2=0,f=0;
	
	 for(j=0;j<len;j++){ 
	    if (a[j]>='0'&&a[j]<='9')
	        s1++;
	 	 else if(a[j]>='A'&&a[j]<='Z')
	 	    z1++;                            //�ж��Ƿ��зǷ��ַ���ͳ���ַ����� 
	 	 else if(a[j]>='a'&&a[j]<='z')
	 	    z2++;
	 	 else 
	 	    f++;
	 } 
	 
	     if(s1>=2&&f==0){    
	     printf("������ϱ�׼,���ָ���Ϊ%d,��д��ĸ����Ϊ%d��,Сд��ĸ����Ϊ%d��",s1,z1,z2); 
	 }
		 else
		   printf("���벻���ϱ�׼,���ָ���Ϊ%d,��д��ĸ����Ϊ%d��,Сд��ĸ����Ϊ%d��",s1,z1,z2); 
	}
	
	
