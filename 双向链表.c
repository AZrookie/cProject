#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct student {
	int num;
	struct student *prior;
	struct student *next;
}Stu,*pStu;
 

int main(int argc, char *argv[]) {
	pStu Head,pNew,pEnd;
	Head=(pStu)malloc(sizeof(Stu));
	Head->next=NULL;//与单链表不同的是要处理前后两个指针域的指向 
	Head->prior=NULL;
	pEnd=Head;
//------------------------------------------------

	int len;
	printf("please input the length of list");
	scanf("%d",&len);
	for(i=0;i<len;i++){
		pNew=(pStu)malloc(sizeof(Stu));
		scanf("%d",&pNew->num);
        pNew->next=NULL;
		pNew->prior=pEnd;//需要注意的就是要将前置节点于前面的节点连接起来 
		pEnd->next=pNew;
		pEnd=pNew;		
	}
	
	
	return 0;
}
