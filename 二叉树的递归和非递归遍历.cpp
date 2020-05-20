#include<stdio.h>
#include<stdlib.h>
 
#define STACKINITSIZE 100//栈的当前最大空间 
#define STACKINCREASESIZE 20//栈每次新增长度 
 
typedef char ElemType;//将char类型命名为ElemType，这样当需要修改数据类型时就可以只改动typedef 

typedef struct tree{//树结构
    ElemType data;
    struct tree * lchild;
    struct tree * rchild;
    unsigned int isOut; //专为后序遍历设置的，0为不需要被输出，1为需要被输出
}TreeNode,*Tree;
 

typedef struct stack{//栈结构
    Tree * base;//栈底 
    Tree * top;//栈顶 
    int stacksize;//栈当前的长度 
}Sqstack;
 
 
/*****************栈的操作声明********************/
//这里的&是c++中的引用，详见博客 
void InitStack( Sqstack &s );//初始化栈
void Push( Sqstack &s, Tree e );//元素入栈，这里传入的是Tree指针，因为引用不能随意更改地址 
void GetTop( Sqstack s, Tree &e );//获得栈顶元素
void Pop( Sqstack &s, Tree &e );//弹出栈顶元素
int StackEmpty( Sqstack s );//判断栈是否为空，为空返回1，否则返回0
/*****************栈的操作声明********************/
 
 
/*****************树的操作声明********************/
void CreateTree(Tree &t);//创建树,以先序序列建立树
void PreOrder(Tree t);//递归先序遍历
void PreOrder1(Tree t);//非递归先序遍历
void InOrder(Tree t);//递归中序遍历
void InOrder1(Tree t);//非递归中序遍历
void PostOrder(Tree t);//递归后序遍历
void PostOrder1(Tree t);//非递归后序遍历
/*****************树的操作声明********************/
 
int main(){
    Tree T;
    printf("\n按先序序列输入结点序列，'#'代表空：");
    CreateTree(T);
 
//    printf("\n非递归先序遍历的结果：");
//    PreOrder1(T);
//    printf("\n递归先序遍历的结果：? ");
//    PreOrder(T);
// 
//    printf("\n非递归中序遍历的结果：");
//    InOrder1(T);
//    printf("\n递归中序遍历的结果：? ");
//    InOrder(T);
// 
    printf("\n非递归后序遍历的结果：");
    PostOrder1(T);
//    printf("\n递归后序遍历的结果：? ");
//    PostOrder(T);
//    printf("\n");
 
}
 
 
/*****************栈的操作定义********************/
void InitStack( Sqstack &s ){//初始化栈
    s.base = (Tree *)malloc(STACKINITSIZE*sizeof(Tree));//这里用.而不是->，
	//因为这里是传入的结构体而不是指针，详见博客 
    if ( !s.base ){
    printf("InitStack内存分配出错\n");
    }
    s.top = s.base;//初始化栈令栈底=栈顶 
    s.stacksize = STACKINITSIZE;//栈的长度=初始长度 
}
 

void Push( Sqstack &s, Tree e ){//元素入栈
    if ( s.top - s.base >= s.stacksize ){//这里指针与指针相减是栈的实际长度 ,详见博客 
    s.base = (Tree *)realloc(s.base,(s.stacksize+STACKINCREASESIZE)*sizeof(Tree));
    //realloc函数，详见博客 
    if ( !s.base ){
        printf("Push内存分配出错\n");
        return ;
        }
 
    s.top = s.base + s.stacksize;//上移至扩容前的最大值 
    s.stacksize += STACKINCREASESIZE;//最大值增加 
    }
    e->isOut = 0;//不需要被输出 
    *s.top++ = e;//先令栈顶=根节点 
}
 

void GetTop( Sqstack s, Tree &e ){//获得栈顶元素
    e = *(s.top - 1);// top指向的是比栈顶更高一层的空间，要先减一层 
}
 
 
void Pop( Sqstack &s, Tree &e ){//弹出栈顶元素
    if ( s.top == s.base ){
    printf("栈为空\n");
    return ;
    }
    e = *(--s.top);//同上，先减在取值 ，因为入栈是指针已经向上自动加了，因此想要获得栈顶元素或出栈时就要先自减在取值 
}
 

int StackEmpty( Sqstack s ){//判断栈是否为空，为空返回1，否则返回0
    if ( s.top == s.base )
    return 1;
    return 0;
}
 
/*****************栈的操作定义********************/
 
 
 
/*****************树的操作定义********************/
void CreateTree(Tree &t){//创建树,以先序序列建立树
    char ch;
    scanf("%c",&ch);
    if ( ch == '#' )//如果当前值为NULL，则返回NULL，递归开始一层层返回，直至t不为NULL 
        t = NULL;
    else{
    t = (Tree)malloc(sizeof(TreeNode));
        if ( !t )
    {
        printf("分配内存出错！");
        return ;
    }
    t->data = ch;
    CreateTree(t->lchild);//套娃，递归创建 
    CreateTree(t->rchild);
    }
}
 
 

void PreOrder(Tree t){//递归先序遍历
    if ( t ){
    printf("%c",t->data);//递归就是套娃，一层层调用，在返回 
    PreOrder(t->lchild);
    PreOrder(t->rchild);
    }
}
 

void PreOrder1(Tree t){//非递归先序遍历
    Tree p = t;
    Sqstack s;
    InitStack(s);
 
    while ( p || !StackEmpty(s) ){
    if ( p ){
        printf("%c",p->data);//先输出当前值 
        Push(s,p);//将当前节点压入栈中，进入左子树 
        p = p->lchild;
    }
    else{//直至左子树完全遍历完，一级级返回 
        Pop(s,p);//出栈，就是返回上一个节点 
        p = p->rchild;//进入右子树 
    }
    }
 
}
 
 

void InOrder(Tree t){//递归中序遍历
   if ( t ){
    InOrder(t->lchild);
    printf("%c",t->data);
    InOrder(t->rchild);
    }
}
 
 

void InOrder1(Tree t){//非递归中序遍历
    Tree p = t;
    Sqstack s;
    InitStack(s); 

    while ( p || !StackEmpty(s) ){
    if ( p ){
        Push(s,p);//先压栈，进入左子树 
        p = p->lchild;
    }
    else
    {
        Pop(s,p);//返回上一级 
        printf("%c",p->data);
        p = p->rchild;
    } 
    }
}
 

void PostOrder(Tree t){//递归后序遍历
    if ( t ){
    PostOrder(t->lchild);
    PostOrder(t->rchild);
    printf("%c",t->data);
    }
}
 
 
void PostOrder1(Tree t){//非递归后序遍历
    t->isOut = 0;//初始化 
    Tree p = t;
    Sqstack s;
    InitStack(s); 
 
    while ( p || !StackEmpty(s) ){
    if ( p ){
        if ( p->isOut ){//左右子树都已输出，则该节点也输出，这是叶子节点 
             Pop(s,p);//出栈，p变为上一级节点 
           printf("%c",p->data);//输出节点 
        if (!StackEmpty(s))//如果栈不为空，获得栈顶元素，这里是输出完非叶子节点后，进入上一级进行LRD输出 
                   GetTop(s,p); //得到弹出节点元素的父节点
             else
               p = NULL;//若栈为空，则p为空 
         }
         else{//若左右子树未完全输出 （非叶子节点）   
            if ( (p->lchild) && (p->lchild->isOut == 1) ){
			//如果存在左子树,并且左子树已经遍历完，那么就将isout设为1，因为此时p已经指向右子树，接下来会进入右子树进行输出，
			//说明该节点已经入栈（因为左子树已经遍历完了），不用再次Push,直接走向右子树       
               p->isOut = 1;
               p = p->rchild;
              }
            else{//这是存在左子树但为遍历完成的非叶子节点的情况 
             Push(s,p);//先入栈，进入左子树输出 
             p = p->lchild;
             }    
         }
        }
        else{//这是不存在左子树的情况 
         if (!StackEmpty(s))//若栈不为空，获取栈顶元素 
            GetTop(s,p); 
         else
            p = NULL;
 
        if ( p->rchild ){//若右子树存在，则一直向下遍历，直至NULL 
            p = p->rchild;
         }
         else{//当不存在右子树时，返回上一级输出 
            Pop(s,p);
            printf("%c",p->data);
            p->isOut = 1;//此时右子树 
            if (!StackEmpty(s))
            {
             GetTop(s,p);
                if ( p->lchild == NULL )
               p->isOut = 1; //右子树已全部输出，将父节点isOut置1
        }
            else
            p = NULL;
        }

        }
    }

}


