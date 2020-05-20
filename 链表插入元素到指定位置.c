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
	pStu pre;                      //pre为前驱结点 
    pre = Head;//找到链表 
    int tempi = 0; 
    for (tempi = 1; tempi < m; tempi++) {
    	pre = pre->next;                 //查找第i个位置的前驱结点 ，这个时候pre正好是目标位置的前面一个 
	}
    pStu pnew;                                //插入的结点为p
    pnew = (pStu)malloc(sizeof(Stu));//因为是节点，所以必须要分配内存，而pre值寻址，本质是指针 
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
