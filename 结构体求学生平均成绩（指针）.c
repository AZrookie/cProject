#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	double number;
	double score1; 
	double score2;
	double score3;
	double score4;
	double average; 
} student,*student1; 

void getInformation(student*a);

int main(int argc, char *argv[]) {
	student stu;
	student1 a = &stu;
	getInformation(a);
	
	return 0;
}

void getInformation(student *a){
	student1 p;
	printf("input name number score\n");
	for(p=a;p<a+5;p++){
		scanf("%d %s %lf %lf %lf %lf",&p->number,&p->name,&p->score1,&p->score2,&p->score3,&p->score4);
		p->average = (p->score1+p->score2+p->score3+p->score4)/4.0;
	//	printf("%f\n",p->score1);
	}
	p=a;
	student1 p1;
	double max = p->average;
	for(p=a;p<a+5;p++){
		if(p->average>max){
			max=p->average;
			p1=p;
		}
	}
	printf("The Highest is %s(%d)\nscore1=%.2f,score2=%.2f,score3=%.2f,score4=%.2f,average=%.2f",p1->name,p1->number,p1->score1,p1->score2,p1->score3,p1->score4,p1->average);

}
