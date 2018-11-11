#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

class CQueue
{
	node *front,*rear;
	public:
	
	CQueue()
	{
		front = NULL;
		rear = NULL;
	}

	void enqueue(int val)
	{
		node* newnode = new node();
		newnode->data = val;
		
		if(front == NULL && rear == NULL)
		{
			front = newnode;
			rear = front;
			rear->next = front;
		}
		else
		{
			rear->next = newnode;
			newnode->next = front;
			rear = newnode;
		}
	}

	void dequeue()
	{
		if(front == NULL)
		{
			cout<<"Underflow"<<endl;
		}
		else if(rear == front)
		{
			node *temp = rear;
			front = NULL;
			rear = NULL;
			delete temp;
		}
		else
		{
			node *temp = front;
			front = front->next;
			rear->next = front;
			free (temp);
		}
	}

	void traverse()
	{
		if(front == NULL && rear == NULL)
			cout<<"Queue is empty"<<endl;
		else
		{
			node* temp = front;
			do
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}while(temp!=front);
			cout<<endl;
		}
	}
};

int main()
{
	CQueue q;
	int choice,num;
	while(true)
	{
		cout<<"Choose from the following options:"<<endl;
		cout<<"1. INSERT"<<endl;
		cout<<"2. DELETE"<<endl;
		cout<<"3. PRINT"<<endl;
		cout<<"4. EXIT"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter a number to insert in queue:"<<endl;
				cin>>num;
				q.enqueue(num);
				break;

			case 2:
				 q.dequeue();
				cout<<"Element Deleted"<<endl;
				break;

			case 3:	
				cout<<"Queue:"<<endl;
				q.traverse();
				break;

			case 4: 
				exit(0);

			default: 
				cout<<"Invalid Choice"<<endl;
				 break;
		}
	}
	return 0;
}
