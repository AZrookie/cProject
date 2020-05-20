#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#ifndef LEN
#define LEN sizeof(struct student)
#endif

 typedef struct student{
	int num;
	float score;
	struct node *next;
}Node,*pNode;//定义节点,p为尾指针； 

pNode create ();
void print(pNode p);
int main(int argc, char *argv[]) {
    pNode Head;
    Head=create();
    print(Head);

	return 0;
}

// pNode create (){
// 	pNode Head=(pNode)malloc(sizeof(Node));//链表头节点 
// 	Head->next=NULL;//末尾为null 
// 	pNode p,pi;//pi为尾指针; 
// 	int i;
// 	pNode p2;//p2为新指针； 
// 	pi=Head;
// 	printf("input:");
// for(i=0;i<10;i++){
// 	p=(pNode)malloc(sizeof(Node));
// 	scanf("%d",&p->data);
// 	pi->next=p;
// 	pi=p;		
// }
// pi->next=NULL;
// return Head;
// }

pNode create (){//不带头节点的单链表
	pNode Head,pNew,pEnd;//Head是头指针，不是头节点
    Head=NULL;//避免Head成为野指针
    pEnd=pNew=(pNode)malloc(LEN);//为尾节点和新节点开辟空间
    scanf("%d %f",&pNew->num,&pNew->score);
    while(pNew->num!=0){
    	if (Head==NULL){
    		Head=pNew;
    	}
    	else{
            pEnd->next=pNew;
            pEnd=pNew;
            pNew=(pNode)malloc(LEN);
            scanf("%d %f",&pNew->num,&pNew->score);
    	}
    }
    pEnd->next=NULL;
    return Head;
}

void print(pNode p){
	while(p!=NULL){
		printf("%d %f\n",p->num,p->score);
		p=p->next;
	}
}




