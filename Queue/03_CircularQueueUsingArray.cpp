#include<iostream>
#include<cstdlib>
using namespace std;
#define N 5
int queue[N],front=-1,rear=-1;

void enqueue(int x)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else if((rear+1)%N==front)
		cout<<"\n!!! Queue is Full!!! "	;
	else
		{
			rear=(rear+1)%N;
			queue[rear]=x;
		}
}
void dequeue()
{
	if(front==-1 && rear==-1)
		cout<<"\n!!! Queue is Empty !!!";
	else if(front==rear)
	{
		cout<<"\nDequed element is :"<<queue[front];
		front=rear=-1;
	}
	else
	{	
		cout<<"\nDequed element is :"<<queue[front];
		front=(front+1)%N;
	}
}
void show()
{
	int i;
	if(front==-1 && rear==-1)
		cout<<"\n!!! Queue is Empty !!!";
	else
	{
		cout<<"\nQueue is: ";
		for(i=front;i!=rear;i=(i+1)%N)
		{
			cout<<queue[i] <<" ";
		}cout<<queue[i] <<" ";
	}
}
int main()
{
	int ch;
	do
	{
		cout<<"\n1.Enqueue\t2.Dequeue\t3.Show\t\t4.Stop :";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter Val to enqueue:";
					int val;
					cin>>val;
					enqueue(val);
					break;
			case 2:dequeue();
					break;
			case 3:show();
					break;
			case 4:cout<<"\nExiting.......";
					exit(0);
					break;
			default:cout<<"\n !!! Invalid Entry !!!";
		}
	}while(ch!=4);
}

