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

void StackInit(Stack* s);//初始化栈 
void StackPush(Stack* s,DataType x);//入栈 
DataType StackPop(Stack* s);//出栈 
DataType StackTop(Stack* s);//插看栈顶 
DataType StackSize(Stack* s);//栈的大小 
int StackEmpty(Stack* s);//判空 

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
	
	//为栈申请空间
	s->base=(DataType*)malloc(length*sizeof(DataType));
	//判断是否申成功
	if(!s->base){
		exit(0);
	} 
	//初始化栈数组空间
	s->top = s->base;//最开始栈顶等于栈底
	s->stackSize = length;
	return ; 
}

void StackPush (Stack* s,DataType x){
	//断言
	assert(s);
	if(s->stackSize==s->top-s->base){//栈的顶部减底部就是栈的长度 ,判断是否满栈 
		printf("空间已满，追加空间");
		s->base = (DataType*)realloc(s->base,(s->stackSize+length)*sizeof(DataType));
		//为栈扩容，重新分配地址 
		if(!s->base){
			exit(0);
		} 
		s->top = s->base+s->stackSize;//将top向上移动stacksize个元素单位 
		s->stackSize+=length;//记录当前的栈长度 
	} 
	*(s->top)=x;//赋值 
	s->top++;//top移向下一个元素，为下一个赋值 
	return ;
} 
 
DataType StackPop(Stack* s){
	assert(s);
	if(StackEmpty(s)){
		printf("栈为空");
		return;
	}
	return *--(s->top);
//优先级 '.' > "--" = '*'
//s.top有两种可能
//一是指向栈顶元素的指针
//二是指向比栈顶元素更高一层的空元素
//从这里的实际情况来看，我判断是第二种情况，当s.top==0时，栈为空。
//--s.top是递减指针，这时s.top就指向真正的栈顶元素了
//*--s.top是是该元素，返回给e
//这样e就得到了真正的栈顶元素，同时栈内元素数目减一
//说白了就是e=stack.pop()操作。
} 

DataType StackTop(Stack* s){
	assert(s);
	if(StackEmpty(s)){
		printf("栈为空");
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

