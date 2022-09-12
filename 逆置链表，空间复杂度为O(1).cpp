#include<stdio.h>
#include<stdlib.h>
//创建链表 
typedef struct LNode
{
	int data;			//设置数据域 
	struct LNode *next;	//设置指针域 
}LNode,*LinkList;
//头插法建立链表 
LinkList List_H(LinkList &L)
{
	LNode *s;			//设置移动指针 
	int x=0;			//初始化，用来输入数据 
	L=(LinkList)malloc(sizeof(LNode));	//分配动态地址 
	L->next=NULL;		//初始化指针域指向空 
	scanf("%d",&x);		//输入数据 
	while(x!=9999)	//终止条件输入9999 
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;		//录入数据 
		s->next=L->next;//将新开辟的指针的next指向头指针的下一个，方便后续插入 
		L->next=s;		//将新开辟的指针插入头指针后 
		scanf("%d",&x);	//再次扫描数据 
	}
	return L;
}
//输出所有结点数据 
LNode prin(LinkList &L)
{
	LNode *p=L->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);	//输出 
		p=p->next;
	}
}

//头插法逆置
LinkList Reverse_1(LinkList L)
{
	LNode *p,*r; 	//初始化两个临时指针 
	p=L->next;		//让p为L的下一个 
	L->next=NULL;	//将L置空，注意此时所有指针的源头可以从p找到 
	while(p!=NULL)	//当p不为零的时候终止循环 
	{
		r=p->next;	//p的下一个的指针赋给r 
		//r的作用是暂存p的下一个，后续赋回p 
		p->next=L->next;	//L的下一个指针赋给p的下一个，也就是插入 
		L->next=p;			//将p插入到L下一个，注意此时p已经存了下一个是原先L的下一个 
		p=r;
	}
	return L;
 } 
//指针反转法逆置
LinkList Reverse_2(LinkList L)
{
	LNode *pre,*p=L->next,*r=p->next; //设置pre，暂存指针，p临时指针，r是“探路指针” 
	p->next=NULL;					//先置空p，因为是指针反转，此时为第一个的p最后会到最后一个，即是置空的
	//注意指针反转法是不利用头指针的，也就是凭借上面三个指针实现头结点以外所有结点的反转 
	while(r!=NULL)
	{
		pre=p;						//存储p 
		p=r;						//令p 存储探路 
		r=r->next;					//探路者探路去了 
		p->next=pre;				//让p的下一个指向原先的存储p，也就是上一个p
		//注意是先让p后移，然后让移动后的p指向前面那个
		//探路指针存在的意义：如果是p=p->next，那么后续pre又赋给了p->next，就会导致原先的p->next消失
		//从而丢失了原先链表中的后续数据 
		//最后的结果就是所有后面的指向了前面的，然后 
	}
	//然后让头结点指向这个就可以了 
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
