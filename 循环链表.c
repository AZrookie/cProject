#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct student {
	int num;
	struct student *next;
}Stu,*pStu; 

int main(int argc, char *argv[]) {
	pStu pNew,Head,pEnd;
	Head=(pStu)malloc(sizeof(Stu));
	pEnd=Head;
	int number:
	printf("please input the number you want to be recorded\n");
	scanf("%d",&number);
	int i;
	for(i=0;i<number;i++){
		pNew=(pStu)malloc(sizeof(Stu));
		scanf("%d",&pNew->num);
		pEnd->next=pNew;
		pEnd=pNew;
	}
	pEnd->next=Head;//ѭ������ĺ��ľ���β�ڵ��ָ����ָ��ͷ�ڵ� 
	
	return 0;
}
