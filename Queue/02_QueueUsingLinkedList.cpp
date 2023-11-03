#include<iostream>
using namespace std;
#include<cstdlib>

struct node
{
	int data;
	struct node *link;
}*front=0,*rear=0,*newnode;
void NewN()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->link=0;
}
void Queue(int x)
{
	NewN();
	//cout<<"\n\nsize of newnode="<<sizeof(front)<<"\n\n";
	newnode->data=x;
	if(front==0 && rear==0)
	{
		front=rear=newnode;
	}
	else
	{
		rear->link=newnode;
		rear=newnode;
	}
}
void Dequeue()
{
	struct node*temp=front;
	if(front==0)
	{
		cout<<"\nEmpty Queue";
	}
	else if(front==rear)
	{
		cout<<"\nDequed emt is "<<front->data<<endl;
		front=rear=0;
		free(temp);
	}
	else
	{
		cout<<"\nDequed emt is "<<front->data<<endl;
		front=front->link;
		free(temp);
	}
}
void show()
{
	struct node* temp;
	temp=front;
	if(front==0)
	{
		cout<<"\nEmpty Queue";
	}
	else
	{
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->link;
	}
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
					Queue(val);
					break;
			case 2:Dequeue();
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

