#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

typedef struct student{
	int num;
	struct student *next;
}*pStu,Stu;

int main(int argc, char *argv[]) {
	pStu pi,p,Head;
	int i;
	Head=(pStu)malloc(sizeof(Stu));
	Head->next = NULL;
	pi = Head;
	for(i=0;i<4;i++){
		p = (pStu)malloc(sizeof(Stu));
		scanf("%d",&p->num);
		pi->next=p;
		pi=p;
	}
	pi->next=NULL;
	
	int x,m;
	printf("please input two interger\nthe first one will be used to instruct the number you want to insert\nand the other one will be used to instruct the place where you want the interger to be insert\n");
	scanf("%d %d",&x,&m);
	pStu pre;                      //preΪǰ����� 
    pre = Head;//�ҵ����� 
    int tempi = 0; 
    for (tempi = 1; tempi < m; tempi++) {
    	pre = pre->next;                 //���ҵ�i��λ�õ�ǰ����� �����ʱ��pre������Ŀ��λ�õ�ǰ��һ�� 
	}
    pStu pnew;                                //����Ľ��Ϊp
    pnew = (pStu)malloc(sizeof(Stu));//��Ϊ�ǽڵ㣬���Ա���Ҫ�����ڴ棬��preֵѰַ��������ָ�� 
    pnew->num = x; 
    pnew->next = pre->next;
    pre->next = pnew;
	
	
	
	pStu p1;
	p1 = (pStu)malloc(sizeof(Stu));
	p1=Head->next;
	while(p1){
		printf("%d",p1->num);
		p1=p1->next;
	}
	
	
	return 0;
}
