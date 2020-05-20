#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE sizeof(struct Student)
#define N 20
typedef struct Student
{	
	char name[20];  			// ����
	char num[5];    			// ѧ��
	float score;    				//�ɼ�  
}Stu; 

int numvalid(char * ch)	;		// �ж϶����ѧ���Ƿ�Ϸ����Ϸ���1�����Ϸ���0 
int scorevalid(float f)	;			// �ж϶���ĳɼ��Ƿ�Ϸ� ���Ϸ���1�����Ϸ���0 
int input(Stu *p);					// �Ӽ��̶������� 
void output(Stu *p,int n);			// ��������ʾ����Ļ 
void load(FILE *fp,Stu *p);		// ���ļ���������  
void save(FILE *fp,Stu *p,int n);	// ������д���ļ� 


int main(void){ 
	int count = 0;
	Stu stud1[N];			// stud1���ڴ�ż��̶��������
	Stu stud2[N];			// stud2���ڴ���ļ���������� 
	FILE *fp;
	count=input(stud1);
	save(fp,stud1,count);
	load(fp,stud2);
	
  output(stud2,count);
return 0;
}

int numvalid(char * ch){
	int i = strlen(ch)<=4?1:0;//ѧ�ų��ȴ���4Ϊ�Ƿ�
	return i;
}

int scorevalid(float f){
	int i = f<=100?1:0;//�ɼ�����100�Ƿ�
	return i;
}

int input(Stu *p){
	int i,count=0;
	Stu *work=p;//����ָ��
	char name[20],num[5];
	float score=0;
	printf("������ѧ����Ϣ (����Ϊ*End*ʱ����)\n");
	scanf("%s",name);
	if(!strcmp(name,"*End*")){
//���ж��Ƿ����������ֱ�ӽ�//���˳����ļ�Ϊ��
		return 0;
	}
	else{
		
	for ( i = 0;(i<10)&&strcmp(name,"*End*")!=0;i++){
//��δ��������������
		scanf("%s %f",num,&score);
		if(!strcmp(name,"*End*")){
			return count;
		}
		if((numvalid(num))&&scorevalid(score)){//�ж�ѧ�ţ��ɼ��Ƿ�Ϸ�����
              work[i].score=score;
              strcpy(work[i].name,name);//���ַ����������и�ֵ
              strcpy(work[i].num,num);
              count++;
		}
		else{
			printf("���������д���������\n");
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
	printf("����               ѧ��     �ɼ�\n");
	for(i=0;i<n;i++){
		printf("%-15s%8s%10.2f\n",work[i].name,work[i].num,work[i].score);
	}
}

void save(FILE *fp,Stu *p,int n){
	fp=fopen("student.txt","w");
	if(!fp){//�ļ���ʧ�ܣ�����NULL
       printf("�ļ���ʧ��\n");
	}
	else{
		int i=0;
	for ( i = 0; i < n; i++){
		fprintf(fp,"%s %s %.2f\n",p[i].name,p[i].num,p[i].score);//����fprintf����//��д���ļ���
	}
	}
	
	fclose(fp);
}

void load(FILE *fp,Stu *p){
	char name[20],num[5];
	float score;
	fp=fopen("student.txt","r");
	if(!fp){
		printf("�ļ���ʧ��!");
	}
	else{
		int k=fscanf(fp,"%s %s %f",name,num,&score);//�ļ������ݣ��������ݸ�//��
		if(k!=3){//�ļ�Ϊ��
			printf("�ļ�Ϊ��\n");
		}
		while(k==3){
			strcpy(p->name,name);//���Ƶ�stud2��
			strcpy(p->num,num);
			p->score=score;
			p++;
			k=fscanf(fp,"%s %s %f",name,num,&score);
		}
	}
}

