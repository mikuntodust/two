#include<iostream>
using namespace std;
static int numbercall=1;
static int numberneedcall=1;
class Queue
{
	public:
		void Clear();
		bool EnQueue(const int item);
		bool DeQueue(int & item);
		bool IsEmpty();
		bool IsFull();
		bool GetFront();
};
class ArrayQueue:public Queue
{
	private:
		int maxSize;
		int window;	//窗口 参数 
		int front;
		int rear;
		int *queue;
	public:
		ArrayQueue(int size,int win)		//构造函数 
		{	
			maxSize = size+1;
			queue=new int[maxSize];
			front = rear =0;
			window=win;
		}
		~ArrayQueue()
		{
			delete[] queue;
		}
		void Clear()
		{
			front = rear;
		}
		bool EnQueue(const int item)		//入队 
		{
			if((rear+1)%maxSize==front)
			{
				cout<<"队列已满，溢出"<<endl;
				return false;
			}
			queue[rear]=item;
			rear = (rear + 1)%maxSize;
			return true;
		}
		bool DeQueue(int & item)		//出队 
		{
			if(front == rear)
			{
				cout<<"队列为空"<<endl;
				return false;
			}
			item = queue[front];
			front = (front + 1)%maxSize;
			return true;
		}
		bool GetFront(int & item)		 //得到队首 
		{
			if(front ==rear)
			{
				cout<<"队列为空"<<endl;
				return false;
			}
			item = queue[front];
			return true;
		}
		int Gettime()			//计算总时间 
		{
			if(front == rear)
			{
				return 0;
			}
			int time=0;
			int temp=front;
			while(front!=rear)
			{
				time+=queue[front];
				front++;
			}
			front=temp;
			return time;
		}
		bool checktime()			//减时间 
		{
			if(front ==rear)
			{
				return false;
			}
			queue[front]--;
			int temp=0;
			if(queue[front]==0)
			{
				cout<<"请"<<numbercall<<"号客户前往"<<window<<"号窗口"<<endl; 
				numbercall++;
				DeQueue(temp);
			}
			return true;
		}
};
void intro();
int main()
{
	ArrayQueue queue1(50,1),queue2(50,2),queue3(50,3),queue4(50,4);
	cout<<"欢迎使用银行叫号系统"<<endl;
	while(1)
	{
		queue1.checktime();
		queue2.checktime();
		queue3.checktime();
		queue4.checktime();
		intro();
		int flag;
		cin>>flag;
		system("cls"); 
		if(flag==1)
		{
			int flag2;
			do
			{
				if(flag2<1&&flag2>4) cout<<"输入错误！请重新输入"<<endl; 
				cout<<"请输入数字选择业务"<<endl;
				cout<<"1.选择开户业务"<<endl;
				cout<<"2.选择取款业务"<<endl;
				cout<<"3.选择存款业务"<<endl;
				cout<<"4.选择销户业务"<<endl;
				cin>>flag2;
				system("cls");
			}while(flag2<1&&flag2>4);
			int x,min;
			switch(flag2)
			{
				case 1:x=20;break;
				case 2:x=15;break;
				case 3:x=10;break;
				case 4:x=25;break;
				default:break;
			}
			int i1,i2,i3,i4;
			i1=queue1.Gettime();
			i2=queue2.Gettime();
			i3=queue3.Gettime();
			i4=queue4.Gettime();
			if(i1<=i2&&i1<=i3&&i1<=i4)	min=1;
			else if(i2<=i3&&i2<=i4)		min=2;
			else if(i3<=i4)				min=3;
			else						min=4;		//寻找最短队列 
			int time;
			switch(min)			//最短队列的入队，并且导出前面的时间 
			{
				case 1:time=queue1.Gettime();queue1.EnQueue(x); 	break;
				case 2:time=queue2.Gettime();queue2.EnQueue(x); 	break;
				case 3:time=queue3.Gettime();queue3.EnQueue(x); 	break;
				case 4:time=queue4.Gettime();queue4.EnQueue(x); 	break;
				default: break;
			};
			cout<<"自动为您选择最短的队伍"<<endl;
			cout<<"您取得"<<numberneedcall<<"号,进入"<<min<<"号窗口,您还需等待"<<time<<"分钟"<<endl; 
			if(time==0)
			{
				cout<<"请直接前往窗口！"<<endl;
				numbercall++; 
			} 
			numberneedcall++;
		}
		if(flag==2)
		{
			exit(0);
		}
		cout<<"参数\t\t一队\t二队\t三队\t四队"<<endl;
		cout<<"剩余时间(分钟)"<<"\t"<<queue1.Gettime()<<"\t"<<queue2.Gettime()<<"\t"<<queue3.Gettime()<<"\t"<<queue4.Gettime();
	} 
	return 0; 
}
void intro()
{
		cout<<endl;
		cout<<"时间过去一分钟"<<endl;
		cout<<endl;
		cout<<"请输入数字选择业务"<<endl;
		cout<<"1.有新客户到达，选择业务并取号"<<endl;
		cout<<"2.退出系统"<<endl;
		cout<<"输入其他不做事，直接时间过去一分钟"<<endl;
		cout<<"当有窗口空闲的时候会自动叫号"<<endl;
}
