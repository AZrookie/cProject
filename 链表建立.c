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
}Node,*pNode;//����ڵ�,pΪβָ�룻 

pNode create ();
void print(pNode p);
int main(int argc, char *argv[]) {
    pNode Head;
    Head=create();
    print(Head);

	return 0;
}

// pNode create (){
// 	pNode Head=(pNode)malloc(sizeof(Node));//����ͷ�ڵ� 
// 	Head->next=NULL;//ĩβΪnull 
// 	pNode p,pi;//piΪβָ��; 
// 	int i;
// 	pNode p2;//p2Ϊ��ָ�룻 
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

pNode create (){//����ͷ�ڵ�ĵ�����
	pNode Head,pNew,pEnd;//Head��ͷָ�룬����ͷ�ڵ�
    Head=NULL;//����Head��ΪҰָ��
    pEnd=pNew=(pNode)malloc(LEN);//Ϊβ�ڵ���½ڵ㿪�ٿռ�
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




