#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
	int num;
	struct Node *next;
}Node,*pNode; 

int main(int argc, char *argv[]) {
	int i;
	pNode pi,p,Head;
	Head=(pNode)malloc(sizeof(Node));
	Head->next = NULL;//注意是->next为空，不能将Head置为空，否则会直接找不到Head的地址，即表链不存在
	pi = Head;//pi要先指向Head才能连成表 
	for(i=0;i<4;i++){
		p=(pNode)malloc(sizeof(Node));//首先申请空间，接着赋值，然后尾节点的指针域指向新节点，尾节点变为新节点 
		scanf("%d",&p->num);
		pi->next=p;
		pi=p;
	}
	pi->next=NULL;
	int x ;
	printf("please input a interger ,and we will insert it into the Head of list\n");
	scanf("%d",&x);
	//头插发的核心是
//	1.将新节点的指针域指向第一个节点（Head->next）
//	2.将头节点指向新节点 
	pNode pnew = (pNode)malloc(sizeof(Node));
	pnew->num=x;
	pnew->next=Head->next;
	Head->next =pnew;
	
	pNode p1;
	p1=Head->next;//注意是先输出的话就是进入循环就输出，那么pi就不能为头节点，因为头节点没有数据，那么循环条件就是p不为空，不然会少输出一个最后一个值
	while(p1){
		printf("%d",p1->num);
		p1=p1->next;//指针域的递增 ，不然死循环一直输出第一个节点
	}

	return 0;
}
