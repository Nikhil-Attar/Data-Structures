#include<iostream>
#include<stdlib.h>
using namespace std;

class LinearArray
{
	int size;
	int arr[20];
	
	public:
		
		LinearArray()
		{
			cout<<"Enter the size of array"<<endl;
			cin>>size;
			
			cout<<"Enter elements"<<endl;
			for(int i=0;i<size;i++)
			{
				cin>>arr[i];
			}
		}
		
		void insert(int val, int pos)
		{
			for(int i=size;i>=pos-1;i--)
			{
				arr[i+1] = arr[i];
			}
			
			arr[pos-1] = val;
			size++;
		}
		
		void del(int pos)
		{
			for(int i=pos-1;i<size;i++)
			{
				arr[i] = arr[i+1];
			}
			size--;
		}
		
		void search(int val)
		{
			int flag = 0;
			int pos;
			
			for(int i=0;i<size;i++)
			{
				if(arr[i] == val)
				{
					flag = 1;
					pos = i+1;
					break;
				}
			}
			
			if(flag == 1)
				cout<<val<<" found at "<<pos<<" position"<<endl;
			else
				cout<<val<<" not found"<<endl;
		}
		
		void display()
		{
			for(int i=0;i<size;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		
};

int main()
{
	LinearArray a;
	int choice,num,pos;
	
	while(true)
	{
		cout<<"1. Insert new element at a specified position"<<endl;
		cout<<"2. Delete element"<<endl;
		cout<<"3. Find location of element"<<endl;
		cout<<"4. Display elements"<<endl;
		cout<<"5. Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{	
			case 1:
				cout<<"Enter the element"<<endl;
				cin>>num;
				cout<<"Enter the position"<<endl;
				cin>>pos;
				a.insert(num,pos);
				break;
			case 2:
				cout<<"Enter the position"<<endl;
				cin>>pos;
				a.del(pos);
				break;
			case 3:
				cout<<"Enter element to search"<<endl;
				cin>>num;
				a.search(num);
				break;
			case 4:
				a.display();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Invalid Choice"<<endl;	
		}
	}
	return 0;
}
