#include<stdio.h>
#include<stdlib.h>
 
#define STACKINITSIZE 100//ջ�ĵ�ǰ���ռ� 
#define STACKINCREASESIZE 20//ջÿ���������� 
 
typedef char ElemType;//��char��������ΪElemType����������Ҫ�޸���������ʱ�Ϳ���ֻ�Ķ�typedef 

typedef struct tree{//���ṹ
    ElemType data;
    struct tree * lchild;
    struct tree * rchild;
    unsigned int isOut; //רΪ����������õģ�0Ϊ����Ҫ�������1Ϊ��Ҫ�����
}TreeNode,*Tree;
 

typedef struct stack{//ջ�ṹ
    Tree * base;//ջ�� 
    Tree * top;//ջ�� 
    int stacksize;//ջ��ǰ�ĳ��� 
}Sqstack;
 
 
/*****************ջ�Ĳ�������********************/
//�����&��c++�е����ã�������� 
void InitStack( Sqstack &s );//��ʼ��ջ
void Push( Sqstack &s, Tree e );//Ԫ����ջ�����ﴫ�����Treeָ�룬��Ϊ���ò���������ĵ�ַ 
void GetTop( Sqstack s, Tree &e );//���ջ��Ԫ��
void Pop( Sqstack &s, Tree &e );//����ջ��Ԫ��
int StackEmpty( Sqstack s );//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
/*****************ջ�Ĳ�������********************/
 
 
/*****************���Ĳ�������********************/
void CreateTree(Tree &t);//������,���������н�����
void PreOrder(Tree t);//�ݹ��������
void PreOrder1(Tree t);//�ǵݹ��������
void InOrder(Tree t);//�ݹ��������
void InOrder1(Tree t);//�ǵݹ��������
void PostOrder(Tree t);//�ݹ�������
void PostOrder1(Tree t);//�ǵݹ�������
/*****************���Ĳ�������********************/
 
int main(){
    Tree T;
    printf("\n�������������������У�'#'����գ�");
    CreateTree(T);
 
//    printf("\n�ǵݹ���������Ľ����");
//    PreOrder1(T);
//    printf("\n�ݹ���������Ľ����? ");
//    PreOrder(T);
// 
//    printf("\n�ǵݹ���������Ľ����");
//    InOrder1(T);
//    printf("\n�ݹ���������Ľ����? ");
//    InOrder(T);
// 
    printf("\n�ǵݹ��������Ľ����");
    PostOrder1(T);
//    printf("\n�ݹ��������Ľ����? ");
//    PostOrder(T);
//    printf("\n");
 
}
 
 
/*****************ջ�Ĳ�������********************/
void InitStack( Sqstack &s ){//��ʼ��ջ
    s.base = (Tree *)malloc(STACKINITSIZE*sizeof(Tree));//������.������->��
	//��Ϊ�����Ǵ���Ľṹ�������ָ�룬������� 
    if ( !s.base ){
    printf("InitStack�ڴ�������\n");
    }
    s.top = s.base;//��ʼ��ջ��ջ��=ջ�� 
    s.stacksize = STACKINITSIZE;//ջ�ĳ���=��ʼ���� 
}
 

void Push( Sqstack &s, Tree e ){//Ԫ����ջ
    if ( s.top - s.base >= s.stacksize ){//����ָ����ָ�������ջ��ʵ�ʳ��� ,������� 
    s.base = (Tree *)realloc(s.base,(s.stacksize+STACKINCREASESIZE)*sizeof(Tree));
    //realloc������������� 
    if ( !s.base ){
        printf("Push�ڴ�������\n");
        return ;
        }
 
    s.top = s.base + s.stacksize;//����������ǰ�����ֵ 
    s.stacksize += STACKINCREASESIZE;//���ֵ���� 
    }
    e->isOut = 0;//����Ҫ����� 
    *s.top++ = e;//����ջ��=���ڵ� 
}
 

void GetTop( Sqstack s, Tree &e ){//���ջ��Ԫ��
    e = *(s.top - 1);// topָ����Ǳ�ջ������һ��Ŀռ䣬Ҫ�ȼ�һ�� 
}
 
 
void Pop( Sqstack &s, Tree &e ){//����ջ��Ԫ��
    if ( s.top == s.base ){
    printf("ջΪ��\n");
    return ;
    }
    e = *(--s.top);//ͬ�ϣ��ȼ���ȡֵ ����Ϊ��ջ��ָ���Ѿ������Զ����ˣ������Ҫ���ջ��Ԫ�ػ��ջʱ��Ҫ���Լ���ȡֵ 
}
 

int StackEmpty( Sqstack s ){//�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
    if ( s.top == s.base )
    return 1;
    return 0;
}
 
/*****************ջ�Ĳ�������********************/
 
 
 
/*****************���Ĳ�������********************/
void CreateTree(Tree &t){//������,���������н�����
    char ch;
    scanf("%c",&ch);
    if ( ch == '#' )//�����ǰֵΪNULL���򷵻�NULL���ݹ鿪ʼһ��㷵�أ�ֱ��t��ΪNULL 
        t = NULL;
    else{
    t = (Tree)malloc(sizeof(TreeNode));
        if ( !t )
    {
        printf("�����ڴ����");
        return ;
    }
    t->data = ch;
    CreateTree(t->lchild);//���ޣ��ݹ鴴�� 
    CreateTree(t->rchild);
    }
}
 
 

void PreOrder(Tree t){//�ݹ��������
    if ( t ){
    printf("%c",t->data);//�ݹ�������ޣ�һ�����ã��ڷ��� 
    PreOrder(t->lchild);
    PreOrder(t->rchild);
    }
}
 

void PreOrder1(Tree t){//�ǵݹ��������
    Tree p = t;
    Sqstack s;
    InitStack(s);
 
    while ( p || !StackEmpty(s) ){
    if ( p ){
        printf("%c",p->data);//�������ǰֵ 
        Push(s,p);//����ǰ�ڵ�ѹ��ջ�У����������� 
        p = p->lchild;
    }
    else{//ֱ����������ȫ�����꣬һ�������� 
        Pop(s,p);//��ջ�����Ƿ�����һ���ڵ� 
        p = p->rchild;//���������� 
    }
    }
 
}
 
 

void InOrder(Tree t){//�ݹ��������
   if ( t ){
    InOrder(t->lchild);
    printf("%c",t->data);
    InOrder(t->rchild);
    }
}
 
 

void InOrder1(Tree t){//�ǵݹ��������
    Tree p = t;
    Sqstack s;
    InitStack(s); 

    while ( p || !StackEmpty(s) ){
    if ( p ){
        Push(s,p);//��ѹջ������������ 
        p = p->lchild;
    }
    else
    {
        Pop(s,p);//������һ�� 
        printf("%c",p->data);
        p = p->rchild;
    } 
    }
}
 

void PostOrder(Tree t){//�ݹ�������
    if ( t ){
    PostOrder(t->lchild);
    PostOrder(t->rchild);
    printf("%c",t->data);
    }
}
 
 
void PostOrder1(Tree t){//�ǵݹ�������
    t->isOut = 0;//��ʼ�� 
    Tree p = t;
    Sqstack s;
    InitStack(s); 
 
    while ( p || !StackEmpty(s) ){
    if ( p ){
        if ( p->isOut ){//�������������������ýڵ�Ҳ���������Ҷ�ӽڵ� 
             Pop(s,p);//��ջ��p��Ϊ��һ���ڵ� 
           printf("%c",p->data);//����ڵ� 
        if (!StackEmpty(s))//���ջ��Ϊ�գ����ջ��Ԫ�أ�������������Ҷ�ӽڵ�󣬽�����һ������LRD��� 
                   GetTop(s,p); //�õ������ڵ�Ԫ�صĸ��ڵ�
             else
               p = NULL;//��ջΪ�գ���pΪ�� 
         }
         else{//����������δ��ȫ��� ����Ҷ�ӽڵ㣩   
            if ( (p->lchild) && (p->lchild->isOut == 1) ){
			//�������������,�����������Ѿ������꣬��ô�ͽ�isout��Ϊ1����Ϊ��ʱp�Ѿ�ָ������������������������������������
			//˵���ýڵ��Ѿ���ջ����Ϊ�������Ѿ��������ˣ��������ٴ�Push,ֱ������������       
               p->isOut = 1;
               p = p->rchild;
              }
            else{//���Ǵ�����������Ϊ������ɵķ�Ҷ�ӽڵ����� 
             Push(s,p);//����ջ��������������� 
             p = p->lchild;
             }    
         }
        }
        else{//���ǲ���������������� 
         if (!StackEmpty(s))//��ջ��Ϊ�գ���ȡջ��Ԫ�� 
            GetTop(s,p); 
         else
            p = NULL;
 
        if ( p->rchild ){//�����������ڣ���һֱ���±�����ֱ��NULL 
            p = p->rchild;
         }
         else{//��������������ʱ��������һ����� 
            Pop(s,p);
            printf("%c",p->data);
            p->isOut = 1;//��ʱ������ 
            if (!StackEmpty(s))
            {
             GetTop(s,p);
                if ( p->lchild == NULL )
               p->isOut = 1; //��������ȫ������������ڵ�isOut��1
        }
            else
            p = NULL;
        }

        }
    }

}


