#include <stdio.h>
#include <stdlib.h>

void ispasswordlegal()
    {  	
     	int i=0,len=0,j=0;
     	int a[200];
        gets(a);
	   while (a[i]!='\0'){ //统计长度 
	   	 i++;
	   	 len++;
	   } 
	    if (len>=6&&len<=15){
	       printf("密码长度合格，为%d",len);
	         }                              //判断长度是否合格 ，合格执行下一个函数，不合格结束 
	    else
	      {
		   printf("密码长度不合格，为%d",len);
	         }
	
	 int s1=0,z1=0,z2=0,f=0;
	
	 for(j=0;j<len;j++){ 
	    if (a[j]>='0'&&a[j]<='9')
	        s1++;
	 	 else if(a[j]>='A'&&a[j]<='Z')
	 	    z1++;                            //判断是否有非法字符并统计字符个数 
	 	 else if(a[j]>='a'&&a[j]<='z')
	 	    z2++;
	 	 else 
	 	    f++;
	 } 
	 
	     if(s1>=2&&f==0){    
	     printf("密码符合标准,数字个数为%d,大写字母个数为%d个,小写字母个数为%d个",s1,z1,z2); 
	 }
		 else
		   printf("密码不符合标准,数字个数为%d,大写字母个数为%d个,小写字母个数为%d个",s1,z1,z2); 
	}
	
	
