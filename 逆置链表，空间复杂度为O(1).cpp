#include<stdio.h>
#include<stdlib.h>
//�������� 
typedef struct LNode
{
	int data;			//���������� 
	struct LNode *next;	//����ָ���� 
}LNode,*LinkList;
//ͷ�巨�������� 
LinkList List_H(LinkList &L)
{
	LNode *s;			//�����ƶ�ָ�� 
	int x=0;			//��ʼ���������������� 
	L=(LinkList)malloc(sizeof(LNode));	//���䶯̬��ַ 
	L->next=NULL;		//��ʼ��ָ����ָ��� 
	scanf("%d",&x);		//�������� 
	while(x!=9999)	//��ֹ��������9999 
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;		//¼������ 
		s->next=L->next;//���¿��ٵ�ָ���nextָ��ͷָ�����һ��������������� 
		L->next=s;		//���¿��ٵ�ָ�����ͷָ��� 
		scanf("%d",&x);	//�ٴ�ɨ������ 
	}
	return L;
}
//������н������ 
LNode prin(LinkList &L)
{
	LNode *p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);	//��� 
		p=p->next;
	}
}

//ͷ�巨����
LinkList Reverse_1(LinkList L)
{
	LNode *p,*r; 	//��ʼ��������ʱָ�� 
	p=L->next;		//��pΪL����һ�� 
	L->next=NULL;	//��L�ÿգ�ע���ʱ����ָ���Դͷ���Դ�p�ҵ� 
	while(p!=NULL)	//��p��Ϊ���ʱ����ֹѭ�� 
	{
		r=p->next;	//p����һ����ָ�븳��r 
		//r���������ݴ�p����һ������������p 
		p->next=L->next;	//L����һ��ָ�븳��p����һ����Ҳ���ǲ��� 
		L->next=p;			//��p���뵽L��һ����ע���ʱp�Ѿ�������һ����ԭ��L����һ�� 
		p=r;
	}
	return L;
 } 
//ָ�뷴ת������
LinkList Reverse_2(LinkList L)
{
	LNode *pre,*p=L->next,*r=p->next; //����pre���ݴ�ָ�룬p��ʱָ�룬r�ǡ�̽·ָ�롱 
	p->next=NULL;					//���ÿ�p����Ϊ��ָ�뷴ת����ʱΪ��һ����p���ᵽ���һ���������ÿյ�
	//ע��ָ�뷴ת���ǲ�����ͷָ��ģ�Ҳ����ƾ����������ָ��ʵ��ͷ����������н��ķ�ת 
	while(r!=NULL)
	{
		pre=p;						//�洢p 
		p=r;						//��p �洢̽· 
		r=r->next;					//̽·��̽·ȥ�� 
		p->next=pre;				//��p����һ��ָ��ԭ�ȵĴ洢p��Ҳ������һ��p
		//ע��������p���ƣ�Ȼ�����ƶ����pָ��ǰ���Ǹ�
		//̽·ָ����ڵ����壺�����p=p->next����ô����pre�ָ�����p->next���ͻᵼ��ԭ�ȵ�p->next��ʧ
		//�Ӷ���ʧ��ԭ�������еĺ������� 
		//���Ľ���������к����ָ����ǰ��ģ�Ȼ�� 
	}
	//Ȼ����ͷ���ָ������Ϳ����� 
	L->next=p;
	return L;
 } 
int main()
{
	LNode *A;
	List_H(A);
	prin(A);
	
	printf("\n");
	Reverse_1(A);
	prin(A);
	Reverse_2(A);
	printf("\n");
	prin(A);
} 
