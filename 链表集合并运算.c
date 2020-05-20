#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;


struct LNode{
	ElemType data;
	struct LNode *next;
};
typedef struct LNode *LinkList;

Status ListLength(LinkList L);
void Union(LinkList *La,LinkList Lb);
Status GetElem(LinkList L,int i,ElemType *e);
Status ListEmpty(LinkList L);
Status LocateElem(LinkList L,ElemType e,Status compare (ElemType a,ElemType b));
Status equal(ElemType a,ElemType b);
Status ListInsert(LinkList *L,int i,ElemType e);
Status ListDelete(LinkList *L,int i,ElemType *e);
void input(LinkList *L);
void output(LinkList *L);

int main(){
	LinkList La;
	LinkList Lb;
	input(&La);
	input(&Lb);
	Union(&La,Lb);
	output(&La);
	return 0;
}

void input(LinkList *L){
	printf("�����뼯����Ԫ�ظ�����"); 
	int num=0,i=0;
	scanf("%d",&num);
	while(num>50||num<0){
		printf("���ݲ�����Ҫ��,����������\n");
		scanf("%d",&num);
	}
	(*L)=(LinkList)malloc(sizeof(struct LNode));//��ͷ�ڵ�ĵ����� 
	(*L)->next=NULL;
	LinkList pEnd,pNew;
	pEnd=(*L);
	for(i=0;i<num;i++){//�������˳�ѭ����β�ڵ�ָ��� 
		pNew=(LinkList)malloc(sizeof(struct LNode));
		scanf("%d",&pNew->data);
		pEnd->next=pNew;
		pEnd=pNew;
	}
	pEnd->next=NULL;
}

void output(LinkList *L){
	LinkList p=(*L)->next;
	if(!p){
		printf("����Ϊ��");
		return;
	}
	printf("%d",p->data);
	p=p->next;
	while(p){
		printf(" %d",p->data);
		p=p->next;
	}
}

Status equal(ElemType a,ElemType b){
	return a==b?TRUE:FALSE;
}

Status ListEmpty(LinkList L){
	if(L->next){
		return FALSE;
	} else{
		return TRUE;
	}
} 

Status ListLength(LinkList L){
	LinkList p = L->next;
	int count=0;
	while(p){
		count++;
		p=p->next;
	}
	return count;
}

Status GetElem(LinkList L,int i,ElemType *e){
	int j=1;
	LinkList p = L->next;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i){
		return ERROR;
	}
	*e=p->data;
	return OK;
}

Status ListInsert(LinkList *L,int i,ElemType e){
	int length=ListLength(*L);
	while(i<1||i>length+1){
		if(i<1){
			printf("����λ�ò���С��1������������\n");
			scanf("%d",&i);
		}else{
			printf("����λ�ò��ܴ��ڼ��ϵĳ���+1������������\n");
			scanf("%d",&i);
		} 
	}
	LinkList p,pre,pNew,pEnd;
	p=(*L)->next;//ָ����Ԫ�ڵ� 
	pEnd=(*L);//ͷ�ڵ� 
	int j=0;
	
	if(!p){//����Ϊ�� �� 
		for(j=0;j<i-1;j++){
			pNew=(LinkList)malloc(sizeof(struct LNode));
			pEnd->next=pNew;
			pEnd=pNew;
		}
		pNew=(LinkList)malloc(sizeof(struct LNode));
		pNew->data=e;
			pEnd->next=pNew;
			pEnd=pNew;
			pEnd->next=NULL;
			return OK;
	}
//	else if(i>length) {//����λ�ô�������ĳ��� ,������Ϊ�� 
//		for(j=0;j<length-1;j++){
//			p=p->next;
//		}
//		pEnd=p;
//		for(j=0;j<i-length-1;j++){
//			pNew=(LinkList)malloc(sizeof(struct LNode));
//			pEnd->next=pNew;
//			pEnd=pNew; 
//		}
//		pNew=(LinkList)malloc(sizeof(struct LNode));
//		pNew->data=e;
//		pEnd->next=pNew;
//		pNew->next=NULL;	
//	}
	else if(i<=length+1){
		pNew=(LinkList)malloc(sizeof(struct LNode));
	    pNew->data=e;
	    pre=(*L);
	 	for(j=1;j<i;j++){
		pre=pre->next;
		p=p->next;
		}
		pre->next=pNew;
		pNew->next=p;
	}
return OK; 

}

Status ListDelete(LinkList *L,int i,ElemType *e){
	if((*L)->next==NULL){
		printf("����Ϊ�գ�����ɾ��\n");
		return ERROR;
	}
	int Length=ListLength(*L);
	if(i>Length||i<1){
		if(i<1){
			printf("ɾ��λ�ò���С��1������������\n");
			scanf("%d",&i);
		}else{
			printf("ɾ��λ�ò��ܴ��ڼ��ϵĳ��ȣ�����������\n");
			scanf("%d",&i);
		} 
	}
	LinkList p,pre,pNew;
//	pNew=(LinkList)malloc(sizeof(struct LNode));
//	pNew->data=e;
	pre=(*L);
	p=(*L)->next;
	int t =0;
	for(t=1;t<i;t++){
		pre=pre->next;
		p=p->next;
	}
	pre->next=p->next;
	*e=p->data;
	p->next=NULL;
	free(p);
return OK;
}

void Union(LinkList *La,LinkList Lb){
	ElemType e;
	int La_len,Lb_len;
	int i;
	La_len=ListLength(*La);
	Lb_len=ListLength(Lb);
	for(i=1;i<=Lb_len;i++){
		GetElem(Lb,i,&e);
		if(!LocateElem(*La,e,equal)){
			ListInsert(La,1,e);
		}
	}
}

Status LocateElem(LinkList L,ElemType e,Status compare (ElemType a,ElemType b)){
	LinkList p=L->next;
	int i=1;
	while(p){
		if(compare(p->data,e)){
			return i;
		}
		p=p->next;
		i++;
	}
	return 0;
}
