#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define length 10

typedef int DataType;

typedef struct Stack{
	DataType* top;
	DataType* base;
	int stackSize;
}Stack;

void StackInit(Stack* s);//��ʼ��ջ 
void StackPush(Stack* s,DataType x);//��ջ 
DataType StackPop(Stack* s);//��ջ 
DataType StackTop(Stack* s);//�忴ջ�� 
DataType StackSize(Stack* s);//ջ�Ĵ�С 
int StackEmpty(Stack* s);//�п� 

int main(int argc, char *argv[]) {
	Stack s;
	int i,x,size;
	StackInit(&s);
	
	StackPush(&s,2);
	StackPush(&s,5);
	StackPush(&s,3);
	
	x=StackTop(&s);
	size=StackSize(&s);
	
	i=s.stackSize;
	printf("%d,%d",i,x);
	system("pause");
	 
	return 0;
}


void StackInit(Stack* s){
	
	//Ϊջ����ռ�
	s->base=(DataType*)malloc(length*sizeof(DataType));
	//�ж��Ƿ���ɹ�
	if(!s->base){
		exit(0);
	} 
	//��ʼ��ջ����ռ�
	s->top = s->base;//�ʼջ������ջ��
	s->stackSize = length;
	return ; 
}

void StackPush (Stack* s,DataType x){
	//����
	assert(s);
	if(s->stackSize==s->top-s->base){//ջ�Ķ������ײ�����ջ�ĳ��� ,�ж��Ƿ���ջ 
		printf("�ռ�������׷�ӿռ�");
		s->base = (DataType*)realloc(s->base,(s->stackSize+length)*sizeof(DataType));
		//Ϊջ���ݣ����·����ַ 
		if(!s->base){
			exit(0);
		} 
		s->top = s->base+s->stackSize;//��top�����ƶ�stacksize��Ԫ�ص�λ 
		s->stackSize+=length;//��¼��ǰ��ջ���� 
	} 
	*(s->top)=x;//��ֵ 
	s->top++;//top������һ��Ԫ�أ�Ϊ��һ����ֵ 
	return ;
} 
 
DataType StackPop(Stack* s){
	assert(s);
	if(StackEmpty(s)){
		printf("ջΪ��");
		return;
	}
	return *--(s->top);
//���ȼ� '.' > "--" = '*'
//s.top�����ֿ���
//һ��ָ��ջ��Ԫ�ص�ָ��
//����ָ���ջ��Ԫ�ظ���һ��Ŀ�Ԫ��
//�������ʵ��������������ж��ǵڶ����������s.top==0ʱ��ջΪ�ա�
//--s.top�ǵݼ�ָ�룬��ʱs.top��ָ��������ջ��Ԫ����
//*--s.top���Ǹ�Ԫ�أ����ظ�e
//����e�͵õ���������ջ��Ԫ�أ�ͬʱջ��Ԫ����Ŀ��һ
//˵���˾���e=stack.pop()������
} 

DataType StackTop(Stack* s){
	assert(s);
	if(StackEmpty(s)){
		printf("ջΪ��");
		return; 
	}
	return *(s->top-1);
}

DataType StackSize(Stack* s){
	return (s->top-s->base);
}

int StackEmpty(Stack* s){
	return 0==(s->top-s->base);
}

