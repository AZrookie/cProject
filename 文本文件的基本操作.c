#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE sizeof(struct Student)
#define N 20
typedef struct Student
{	
	char name[20];  			// 姓名
	char num[5];    			// 学号
	float score;    				//成绩  
}Stu; 

int numvalid(char * ch)	;		// 判断读入的学号是否合法，合法：1，不合法：0 
int scorevalid(float f)	;			// 判断读入的成绩是否合法 ，合法：1，不合法：0 
int input(Stu *p);					// 从键盘读入数据 
void output(Stu *p,int n);			// 将数据显示到屏幕 
void load(FILE *fp,Stu *p);		// 从文件读入数据  
void save(FILE *fp,Stu *p,int n);	// 将数据写入文件 


int main(void){ 
	int count = 0;
	Stu stud1[N];			// stud1用于存放键盘读入的数据
	Stu stud2[N];			// stud2用于存放文件读入的数据 
	FILE *fp;
	count=input(stud1);
	save(fp,stud1,count);
	load(fp,stud2);
	
  output(stud2,count);
return 0;
}

int numvalid(char * ch){
	int i = strlen(ch)<=4?1:0;//学号长度大于4为非法
	return i;
}

int scorevalid(float f){
	int i = f<=100?1:0;//成绩大于100非法
	return i;
}

int input(Stu *p){
	int i,count=0;
	Stu *work=p;//工作指针
	char name[20],num[5];
	float score=0;
	printf("请输入学生信息 (姓名为*End*时结束)\n");
	scanf("%s",name);
	if(!strcmp(name,"*End*")){
//先判断是否结束，是则直接结//束退出，文件为空
		return 0;
	}
	else{
		
	for ( i = 0;(i<10)&&strcmp(name,"*End*")!=0;i++){
//若未结束，继续输入
		scanf("%s %f",num,&score);
		if(!strcmp(name,"*End*")){
			return count;
		}
		if((numvalid(num))&&scorevalid(score)){//判断学号，成绩是否合法输入
              work[i].score=score;
              strcpy(work[i].name,name);//用字符串函数进行赋值
              strcpy(work[i].num,num);
              count++;
		}
		else{
			printf("数据输入有错重新输入\n");
			i--;
		}
		scanf("%s",name);
	}
return count;
	}
	
}

void output(Stu *p,int n){
	int i;
	Stu *work=p;
	printf("姓名               学号     成绩\n");
	for(i=0;i<n;i++){
		printf("%-15s%8s%10.2f\n",work[i].name,work[i].num,work[i].score);
	}
}

void save(FILE *fp,Stu *p,int n){
	fp=fopen("student.txt","w");
	if(!fp){//文件打开失败，返回NULL
       printf("文件打开失败\n");
	}
	else{
		int i=0;
	for ( i = 0; i < n; i++){
		fprintf(fp,"%s %s %.2f\n",p[i].name,p[i].num,p[i].score);//调用fprintf将数//据写入文件中
	}
	}
	
	fclose(fp);
}

void load(FILE *fp,Stu *p){
	char name[20],num[5];
	float score;
	fp=fopen("student.txt","r");
	if(!fp){
		printf("文件打开失败!");
	}
	else{
		int k=fscanf(fp,"%s %s %f",name,num,&score);//文件有数据，返回数据个//数
		if(k!=3){//文件为空
			printf("文件为空\n");
		}
		while(k==3){
			strcpy(p->name,name);//复制到stud2中
			strcpy(p->num,num);
			p->score=score;
			p++;
			k=fscanf(fp,"%s %s %f",name,num,&score);
		}
	}
}

