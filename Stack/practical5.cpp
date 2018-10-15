#include<iostream>
#include<stdlib.h>
using namespace std;

class stack
{
	int top;
	int *arr;
	int size;
	
	public:
	
	stack()
	{
		cout<<"Enter size of stack"<<endl;
		cin>>size;
		arr = new int[size];
		top = -1;
	}
	
	void push(int val)
	{
		if(top == size-1)
		{
			cout<<"Overflow"<<endl;
		}
		else
		{
			top++;
			arr[top] = val;
		}
	}
	
	int pop()
	{
		int item = 0;
		if(top == -1)
		{
			cout<<"Underflow"<<endl;
		}
		else
		{
		item = arr[top];
		top--;
		}
		return item;
	}
	
	int peek()
	{
		if(top == -1)
		{
			cout<<"The stack is empty"<<endl;
		}
		return arr[top];
	}
};

int main()
{
	stack s;
	int choice,val;
	
	while(true)
	{
	cout<<"1. PUSH"<<endl;
	cout<<"2. POP"<<endl;
	cout<<"3. PEEK"<<endl;
	cout<<"4. EXIT"<<endl;
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"Enter value"<<endl;
			cin>>val;
			s.push(val);
			break;
		case 2:
			cout<<"Poped: "<<s.pop()<<endl;
			break;
		case 3:
			cout<<"Top Element: "<<s.peek()<<endl;
			break;
		case 4:
			exit(0);
		default:
			cout<<"Invalid Choice"<<endl;
	}
	

	}
	return 0;
}
