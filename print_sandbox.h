#include <stdlib.h>
#include <stdio.h>

void print_sandbox(int N,char a[]){

	int line=1,sum_N=1;
	while(N>sum_N&&(N-sum_N)>=2*(line+2)){
		line=line+2;                                                   //����������
		sum_N+=2*(line);
	}
	//	printf("%d %d",sum_N,line); 
		                                                //�������;
	int upper_line,i,j,j1,n=0,t,lower_line,t1=1,n2=1;
	upper_line=(line-1)/2;     //�����ϲ��ж����У� 
	t=upper_line;    //��t�����㣬����iѭ����upper����line�������٣� 
    lower_line=upper_line; 
for(i=0;i<upper_line;i++){                                  
		for(j1=0;j1<n;j1++){//n��������ո����� 
		printf(" ");
	    }                    
             n=j1+1;
	   for(j=0;j<t*2+1;j++){                       //t������forѭ�����Լ�������һ��ѭ����������� 
	        printf("%c",a);
	    }  
		printf("\n");                                    //����ַ�
         t--; 
  }   
  
  for(i=0;i<upper_line;i++){
  	printf(" ");
  }
  printf("%c\n",a);
  
                                               //����²��ַ� 
  for(i=0;i<lower_line;i++){                                  
		for(j1=0;j1<lower_line-n2;j1++){//n��������ո����� 
		printf(" ");
	    }                    
             n2++;
	   for(j=0;j<t1*2+1;j++){                       //t������forѭ�����Լ�������һ��ѭ����������� 
	        printf("%c",a);
	    }  
		printf("\n");                                    //����ַ�
         t1++; 
  }   
           
	printf("%d",N-sum_N);	                                                                                                   
}                                                          

