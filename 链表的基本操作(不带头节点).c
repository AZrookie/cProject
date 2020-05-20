#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#ifndef LEN
#define LEN sizeof(struct student)
#endif

 typedef struct student{
    int num;
    float score;
    struct student *next;
}Node,*pNode;//定义节点,p为尾指针； 

pNode create ();
void print(pNode Head);
void serch (pNode Head,float n);
pNode del(pNode Head,float n);
pNode add(pNode,int num,float n);

int main(int argc, char *argv[]) {
    pNode Head,p;
    Head=create();
    printf("\n");
    print(Head);
    printf("\n");
    printf("链表中60分以下同学：\n");
    printf("\n");
    serch(Head,60);
    printf("删除链表中60分以下同学后的新链表：\n");
    p=del(Head,60);
    print(p);
    printf("\n");
    printf("添加学号为10，成绩为70的同学到链表中：\n");
    p=add(Head,10,70);
    print(p);
    return 0;
}



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

void print(pNode Head){
    pNode p;
    p=Head;
    while(p!=NULL){
        printf("%d %.2f\n",p->num,p->score);
        p=p->next;
    }
}


void serch (pNode Head,float n){
    pNode p;
    p=Head;
    float target=n;
    while(p!=NULL){
        if (p->score<target){
            printf("%d %.2f\n",p->num,p->score);
        }
        p=p->next;
    }
}

pNode del(pNode Head,float n){//暂时不能处理第一个 ，最后一个可以处理,可以用一个头节点解决 
    float target=n;
    pNode pre,p,t;
    p=Head->next;
    pre=Head;
    //之前的内存溢出是因为写成了pre=p=Head;
    //这样会导致后面的指针删除出现错误，即自身对自身进行操作 
    
    
        while(p!=NULL){
            if(Head->score<n){
        Head=Head->next;
        p=Head->next;
        pre=Head;//删除首元节点后还要对p和pre重新赋值 ，不能放在while外面，不然只能删除一次
        //当删除第一个节点后，如果第二个节点也<60，就删除不了了，因为第二个节点变成了第一个
        //节点，而第一个节点只进行了一次操作 
    }
            
        if (p->score<target){
            pre->next=p->next;
            t=p->next;
            p->next=NULL;//可加可不加，free掉之后就不存在了 
            free(p);
            p=t;//这里出错，不能全部删除的原因是 free掉p后的问题是p指向哪
            //如果，没有底下的else，pre就会指向原来的p，而原来的p的指向已经删除了
            //这样删除一次过后就会跳过下一次的判定，导致漏掉 
        }
        else{
            pre=p;
        p=p->next;
        }
    }
    return Head;
      
}

pNode add(pNode Head,int num,float n){
    pNode p,pre,pNew,t;
    pNew=(pNode)malloc(LEN);
    pNew->num=num;
    pNew->score=n;
    pre=Head;
    p=Head->next;
    
    if(Head->num>num){
        t=Head;
        Head=pNew;
        pNew->next=t;
        pre=Head;
    p=Head->next;
    }
    
    while(p!=NULL){
        
        if (p->num>num){
           pre->next=pNew;
           pNew->next=p;
           return Head;
        }
        else{
           pre=p;
           p=p->next;
        }
    }
     pre->next=pNew;
           pNew->next=p;
           return Head;
}