#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	double score[3][4];//定义二维数组 
	int i,j,i1,i2,i3;
	double (*p)[4],(*pi)[4];//定义行指针 
 
    printf("input students score:\n");
	for(p=score,j=0;p<score+3;p++,j++){//二维数组名是行指针
			printf("student %d:",j);//输出第几个学生
		
		for(i=0;i<4;i++){
			scanf("%lf",*p+i);//i¿ØÖÆÃ¿ÐÐµÄµÚ¼¸¸ö 
	     }
	}
	 pi=score;//Êä³öÓÃµÄÐÂÖ¸Õë 
	int number;
	printf("input student No:");  //ÕÒµ½µÚ¼¸¸öÑ§Éú 
	scanf("%d",&number);
	if(number==0){
		printf("the score of No %d are:",number);
		for(i=0;i<4;i++){
			printf("%.1lf  ",*(*(pi)+i));  //piÖ¸ÏòµÚÒ»ÐÐ 
		}
	}
	else  if(number==1){
		printf("the score of No %d are:",number);
		for(i=0;i<4;i++){
			printf("%.1lf  ",*(*(pi+1)+i));//piÖ¸ÏòµÚ¶þÐÐ 
		}
	}
	else if(number==2){
		printf("the score of No %d are:",number);
		for(i=0;i<4;i++){                //piÖ¸ÏòµÚÈýÐÐ 
			printf("%.1lf  ",*(*(pi+2)+i));
		}
	}
	
	
	return 0;
}
