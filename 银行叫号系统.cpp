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
		int window;	//���� ���� 
		int front;
		int rear;
		int *queue;
	public:
		ArrayQueue(int size,int win)		//���캯�� 
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
		bool EnQueue(const int item)		//��� 
		{
			if((rear+1)%maxSize==front)
			{
				cout<<"�������������"<<endl;
				return false;
			}
			queue[rear]=item;
			rear = (rear + 1)%maxSize;
			return true;
		}
		bool DeQueue(int & item)		//���� 
		{
			if(front == rear)
			{
				cout<<"����Ϊ��"<<endl;
				return false;
			}
			item = queue[front];
			front = (front + 1)%maxSize;
			return true;
		}
		bool GetFront(int & item)		 //�õ����� 
		{
			if(front ==rear)
			{
				cout<<"����Ϊ��"<<endl;
				return false;
			}
			item = queue[front];
			return true;
		}
		int Gettime()			//������ʱ�� 
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
		bool checktime()			//��ʱ�� 
		{
			if(front ==rear)
			{
				return false;
			}
			queue[front]--;
			int temp=0;
			if(queue[front]==0)
			{
				cout<<"��"<<numbercall<<"�ſͻ�ǰ��"<<window<<"�Ŵ���"<<endl; 
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
	cout<<"��ӭʹ�����нк�ϵͳ"<<endl;
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
				if(flag2<1&&flag2>4) cout<<"�����������������"<<endl; 
				cout<<"����������ѡ��ҵ��"<<endl;
				cout<<"1.ѡ�񿪻�ҵ��"<<endl;
				cout<<"2.ѡ��ȡ��ҵ��"<<endl;
				cout<<"3.ѡ����ҵ��"<<endl;
				cout<<"4.ѡ������ҵ��"<<endl;
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
			else						min=4;		//Ѱ����̶��� 
			int time;
			switch(min)			//��̶��е���ӣ����ҵ���ǰ���ʱ�� 
			{
				case 1:time=queue1.Gettime();queue1.EnQueue(x); 	break;
				case 2:time=queue2.Gettime();queue2.EnQueue(x); 	break;
				case 3:time=queue3.Gettime();queue3.EnQueue(x); 	break;
				case 4:time=queue4.Gettime();queue4.EnQueue(x); 	break;
				default: break;
			};
			cout<<"�Զ�Ϊ��ѡ����̵Ķ���"<<endl;
			cout<<"��ȡ��"<<numberneedcall<<"��,����"<<min<<"�Ŵ���,������ȴ�"<<time<<"����"<<endl; 
			if(time==0)
			{
				cout<<"��ֱ��ǰ�����ڣ�"<<endl;
				numbercall++; 
			} 
			numberneedcall++;
		}
		if(flag==2)
		{
			exit(0);
		}
		cout<<"����\t\tһ��\t����\t����\t�Ķ�"<<endl;
		cout<<"ʣ��ʱ��(����)"<<"\t"<<queue1.Gettime()<<"\t"<<queue2.Gettime()<<"\t"<<queue3.Gettime()<<"\t"<<queue4.Gettime();
	} 
	return 0; 
}
void intro()
{
		cout<<endl;
		cout<<"ʱ���ȥһ����"<<endl;
		cout<<endl;
		cout<<"����������ѡ��ҵ��"<<endl;
		cout<<"1.���¿ͻ����ѡ��ҵ��ȡ��"<<endl;
		cout<<"2.�˳�ϵͳ"<<endl;
		cout<<"�������������£�ֱ��ʱ���ȥһ����"<<endl;
		cout<<"���д��ڿ��е�ʱ����Զ��к�"<<endl;
}
