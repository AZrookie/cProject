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
	Head->next = NULL;//ע����->nextΪ�գ����ܽ�Head��Ϊ�գ������ֱ���Ҳ���Head�ĵ�ַ��������������
	pi = Head;//piҪ��ָ��Head�������ɱ� 
	for(i=0;i<4;i++){
		p=(pNode)malloc(sizeof(Node));//��������ռ䣬���Ÿ�ֵ��Ȼ��β�ڵ��ָ����ָ���½ڵ㣬β�ڵ��Ϊ�½ڵ� 
		scanf("%d",&p->num);
		pi->next=p;
		pi=p;
	}
	pi->next=NULL;
	int x ;
	printf("please input a interger ,and we will insert it into the Head of list\n");
	scanf("%d",&x);
	//ͷ�巢�ĺ�����
//	1.���½ڵ��ָ����ָ���һ���ڵ㣨Head->next��
//	2.��ͷ�ڵ�ָ���½ڵ� 
	pNode pnew = (pNode)malloc(sizeof(Node));
	pnew->num=x;
	pnew->next=Head->next;
	Head->next =pnew;
	
	pNode p1;
	p1=Head->next;//ע����������Ļ����ǽ���ѭ�����������ôpi�Ͳ���Ϊͷ�ڵ㣬��Ϊͷ�ڵ�û�����ݣ���ôѭ����������p��Ϊ�գ���Ȼ�������һ�����һ��ֵ
	while(p1){
		printf("%d",p1->num);
		p1=p1->next;//ָ����ĵ��� ����Ȼ��ѭ��һֱ�����һ���ڵ�
	}

	return 0;
}
