#include<iostream>
using namespace std;

class postfixEval
{
	int top;
	int size;
	char *arr;
	char *ch;
	
	public:
	
	void expression()
	{
		top = -1;
		cout<<"Enter the size of expression"<<endl;
		cin>>size;
		arr = new char[size];
		ch = new char[size];
		
		cout<<"Enter expression"<<endl;
		
		for(int i=0;i<size;i++)
			cin>>ch[i];
			
	}
	
	void push(char val)
	{
		if(top == size-1)
			cout<<"Overflow"<<endl;
		else
		{
			top++;
			arr[top] = val;
		}
	}
	
	char pop()
	{
		char item = '!';
		if(top == -1)
			cout<<"Underflow"<<endl;
		else
		{
		item = arr[top];
		top--;
		}
		return item;
	}
	
	int eval()
	{
		int res;
		for(int i=0;i<size;i++)
		{
			if(ch[i] >= '0' && ch[i] <= '9')
			{
				push(ch[i]);
			}
			else if(ch[i] == '+')
			{
				int b = pop() - '0';
				int a = pop() - '0';
				
				 res = a+b;
				 char c = res + '0';
				 push(c);
			}
			else if(ch[i] == '-')
			{
				int b = pop() - '0';
				int a = pop() - '0';
				
				 res = a-b;
				 char c = res + '0';
				 push(c);
			}
			else if(ch[i] == '*')
			{
				int b = pop() - '0';
				int a = pop() - '0';
				
				 res = a*b;
				 char c = res + '0';
				 push(c);
			}
			else if(ch[i] == '/')
			{
				int b = pop() - '0';
				int a = pop() - '0';
				
				 res = a/b;
				 char c = res + '0';
				 push(c);
			}
		}
		
		char r = arr[top];
		int f = r - '0';
		return f;	
	}
};

class InfixToPostfix
{
	int top;
	int size;
	char *arr;
	char *exp;
	
	public:
	
	void expression()
	{
		top = -1;
		cout<<"Enter the size of expression"<<endl;
		cin>>size;
		exp = new char[size];
		arr = new char[size];
		
		cout<<"Enter expression"<<endl;
		
		for(int i=0;i<size;i++)
			cin>>exp[i];
	}
	
	void push(char c)
	{
		top++;
		arr[top] = c;
	}
	
	char pop()
	{
		int item;
		item = arr[top];
		top--;
		return item;
	}
	
	int priority(char c)
	{
		if(c == '(')
			return 0;
		else if(c == '+' || c == '-')
			return 1;
		else if(c == '*' || c == '/')
			return 2;
		else if(c == '^')
			return 3;
	}
	
	void inToPost()
	{
		char x;
		for(int i=0;i<size;i++)
		{
			if(isalnum(exp[i]))
			{
				cout<<exp[i];
			}
			else if(exp[i] == '(')
			{
				push(exp[i]);
			}
			else if(exp[i] == ')')
			{
				while((x = pop())!='(')
					cout<<x;
			}
			else
			{
				while(priority(exp[i]) <= priority(arr[top]))
					cout<<pop();
				
				push(exp[i]);
			}
		}
		
		while(top!= -1)
			cout<<pop();
			
		cout<<endl;
	}
	
};

int main()
{
	cout<<"1. Convert arithmetic expression from infix notation to postfix notation"<<endl;
	cout<<"2. Evaluate postfix expression"<<endl;
	cout<<"Enter choice: ";
	
	int choice,result;
	cin>>choice;
	
	InfixToPostfix itp;
	postfixEval p;
	
	switch(choice)
	{
		case 1:
			itp.expression();
			itp.inToPost();
			break;
		case 2:
			p.expression();
			result = p.eval();
			cout<<result<<endl;
			break;
		default:
			cout<<"Invalid Choice"<<endl;
	}
	
	return 0;
}
