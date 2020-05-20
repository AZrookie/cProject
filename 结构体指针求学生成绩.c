#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	int number;
	int score;
} student,*student1; 

void getInformation(student*a);

int main(int argc, char *argv[]) {
	student stu;
	student1 a = &stu;
	getInformation(a);
	
	return 0;
}

void getInformation(student *a){
	student *p;
	printf("input name number score");
	for(p=a;p<a+5;p++){
		scanf("%s %d %d",&p->name,&p->number,&p->score);
		if(p->score>100||p->score<0){
			printf("请重新输入正确的成绩\n");
			p--;
		}
	}
for(p=a;p<a+5;p++){
		printf("failed the exam:")
		if(p->score<60){
			printf("%d/%s,%d\n",p->number,p->name,p->score);
		}
	}

}
