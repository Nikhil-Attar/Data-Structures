#include<iostream>
#include<stdlib.h>
using namespace std;

class CQueue 
{
	int *arr;
	int size,front,rear;
	
	public:
		CQueue()
		{
			cout<<"Enter size of queue"<<endl;
			cin>>size;
			arr = new int[size];
			front = -1;
			rear = -1;
		}
	
		void enqueue(int val)
		{
			if(front == (rear+1)%size||front == 0 && rear == size-1)
			{
				cout<<"Overflow"<<endl;
			}
			else if(front == -1 && rear == -1)
			{
				front = 0;
				rear = 0;
				arr[rear] = val;
			}
			else
			{
				rear = (rear+1)%size;
				arr[rear] = val;
			}
		}

		void dequeue()
		{
			if(front == -1)
			{
				cout<<"Underflow"<<endl;
			}
			else if(front == rear)
			{
				front = -1;
				rear = -1;
			}
			else if(front == size - 1)
			{
				front = 0;
			}
			else
				front++;
		}

		void traverse()
		{
			if(front == -1 && rear == -1)
			{
				cout<<"Queue is empty"<<endl;
				return;
			}
			
			cout<<"Queue : ";
			
			if(rear >= front)
			{
				for(int i = front;i <= rear; i++)
				{
					cout<<arr[i]<<"\t";
				}
				cout<<endl;
			}
			else
			{
				for(int i = front;i < size;i++)
				{
					cout<<arr[i]<<"\t";
				}
				for(int i = 0;i <= rear;i++)
				{
					cout<<arr[i]<<"\t";
				}
				cout<<endl;
			}
		}
};

int main()
{
	CQueue c;
	
	while(true)
	{
		cout<<"Enter a number to perform following operation"<<endl;
		cout<<"1. ENQUEUE"<<endl;
		cout<<"2. DEQUEUE"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. EXIT"<<endl;
	
		int choice,num;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Add an element in the queue"<<endl;
				cin>>num;
				c.enqueue(num);
				break;
					
			case 2:
				c.dequeue();
				cout<<"Element deleted"<<endl;
				break;
					
			case 3:
				c.traverse();
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

