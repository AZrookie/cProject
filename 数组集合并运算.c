#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;

typedef struct {
	ElemType data[MAXSIZE];
	int length;

} Sqlist;

void Union (Sqlist *La,Sqlist Lb);
Status ListLength(Sqlist L);
Status GetElem (Sqlist L,int i, ElemType *e);
Status LocateElem (Sqlist L,ElemType e,Status compare(ElemType a1,ElemType a2));
Status ListInsert(Sqlist *L,int i,ElemType e);
Status ListEmpty(Sqlist L);
Status ListDelete (Sqlist *L,int i,ElemType *e);
Status equal(ElemType a1,ElemType a2);
Status input(Sqlist *L);
void output(Sqlist *L);
void empty(Sqlist *L);

int main(int argc, char const *argv[]) {
	Sqlist La,Lb;
	input(&La);
	input(&Lb);
	Union(&La,Lb);
	output(&La);
//printf("%d",LocateElem(La,3,equal));	
	return 0;
}

Status ListLength(Sqlist L) {
	return L.length;
}

Status input(Sqlist *L) {
	printf("请输入集合中元素个数：");
	int num=0;
	scanf("%d",&num);
	L->length=0;
	while(num>20||num<0) {
		printf("数据不符合要求,请重新输入\n");
		scanf("%d",&num);
	}
	L->length=num;
	int i;
	for(i=0; i<num; i++) {//是0直接跳过循环，集合为空 
		scanf("%d",&L->data[i]);
	}
	return OK;
}

Status GetElem (Sqlist L,int i, ElemType *e) {
	if(L.length==0||i<1||i>L.length) {//i是指位置，第一个位置的下标是0 
		return ERROR;
	}
	*e = L.data[i-1];
	return OK;
}

Status ListEmpty(Sqlist L) {
	if(L.length==0) {
		return TRUE;
	} else {
		return FALSE;
	}
	return OK;
}

void Union (Sqlist *La,Sqlist Lb) {
	ElemType e;
	int La_len,Lb_len;
	int i;
	La_len=ListLength(*La);
	Lb_len=ListLength(Lb);
	for(i=1; i<=Lb_len; i++) {
		GetElem(Lb,i,&e);
		if(!LocateElem(*La,e,equal)) {
			ListInsert(La,++La_len,e);
		}
	}
}

Status equal(ElemType a1,ElemType a2) {
	if(a1==a2) {
		return TRUE;
	}
	return FALSE;
}

Status LocateElem (Sqlist L,ElemType e,Status compare(ElemType a1,ElemType a2)) {
	int i=0;
	for(i=0; i<L.length; i++) {//如果链表为空，跳过循环，返回0 
		if(compare(L.data[i],e)) {
			return i+1;
		}
	}
	return 0;
}

Status ListInsert(Sqlist *L,int i,ElemType e) {
	while(i<1||i>L->length+1){
		if(i<1){
			printf("插入位置不能小于1，请重新输入\n");
			scanf("%d",&i);
		}else{
			printf("插入位置不能大于集合的长度+1，请重新输入\n");
			scanf("%d",&i);
		} 
	}
	int j=i;
	if(!L->length) { //集合为空，除插入数外为随机数
//		printf("集合为空，除插入的第%d个数外其余都为随机数\n",i); 
		L->data[i-1]=e;
		L->length+=i;
	} else if(i<=L->length+1) {
		for(j=L->length; j>=i; j--) {//将i之后的数据全部后移 
			L->data[j]=L->data[j-1];
		}
		L->data[j]=e; //数据赋给i位 
		L->length++;
	}
	return OK;
}

void output(Sqlist *L) {
	if(!L->length) {
		printf("集合为空\n");
		return;
	}
	int i=0;
	printf("%d",L->data[0]);
	for(i=1; i<L->length; i++) {
		printf("% d",L->data[i]);
	}
	printf("\n");
}

Status ListDelete (Sqlist *L,int i,ElemType *e) {
	if(!L->length){
		printf("集合为空，不能删除\n");
		return ERROR;
	}
	while(i<1||i>L->length){
		if(i<1){
			printf("删除位置不能小于1，请重新输入\n");
			scanf("%d",&i);
		}else{
			printf("删除位置不能大于集合的长度，请重新输入\n");
			scanf("%d",&i);
		} 
	}
	int j=0;
	*e=L->data[i-1];
	for(j=i-1;j+1<L->length;j++){
		L->data[j]=L->data[j+1];
	}
	L->length--;
	return OK;
}

void empty(Sqlist *L) {
	L->length=0;
}
