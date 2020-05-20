#include <stdlib.h>
#include <stdio.h>

void print_sandbox(int N,char a[]){

	int line=1,sum_N=1;
	while(N>sum_N&&(N-sum_N)>=2*(line+2)){
		line=line+2;                                                   //计算行数；
		sum_N+=2*(line);
	}
	//	printf("%d %d",sum_N,line); 
		                                                //输出符号;
	int upper_line,i,j,j1,n=0,t,lower_line,t1=1,n2=1;
	upper_line=(line-1)/2;     //计算上部有多少行； 
	t=upper_line;    //用t来运算，避免i循环中upper——line次数减少； 
    lower_line=upper_line; 
for(i=0;i<upper_line;i++){                                  
		for(j1=0;j1<n;j1++){//n控制输出空格数； 
		printf(" ");
	    }                    
             n=j1+1;
	   for(j=0;j<t*2+1;j++){                       //t不能在for循环里自减，否则一次循环都不能完成 
	        printf("%c",a);
	    }  
		printf("\n");                                    //输出字符
         t--; 
  }   
  
  for(i=0;i<upper_line;i++){
  	printf(" ");
  }
  printf("%c\n",a);
  
                                               //输出下部字符 
  for(i=0;i<lower_line;i++){                                  
		for(j1=0;j1<lower_line-n2;j1++){//n控制输出空格数； 
		printf(" ");
	    }                    
             n2++;
	   for(j=0;j<t1*2+1;j++){                       //t不能在for循环里自减，否则一次循环都不能完成 
	        printf("%c",a);
	    }  
		printf("\n");                                    //输出字符
         t1++; 
  }   
           
	printf("%d",N-sum_N);	                                                                                                   
}                                                          

