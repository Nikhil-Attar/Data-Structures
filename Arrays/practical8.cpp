#include<iostream>
#include<stdlib.h>
using namespace std;

class InsertionSort
{
	int size;
	int *arr;
	
	public:
	
		InsertionSort()
		{
			cout<<"Enter the size of array"<<endl;
			cin>>size;
			arr = new int[size];
			
			cout<<"Enter elements"<<endl;
			for(int i=0;i<size;i++)
			{
				cin>>arr[i];
			}
		}
		
		void sort()
		{
			int i,j;
			int key;
			
  			for (i=1;i<size;i++) 
   			{ 
			       key = arr[i]; 
			       j = i-1; 
  
			       		while (j>=0 && arr[j] > key) 
			       		{ 
			           		arr[j+1] = arr[j]; 
			           		j = j-1; 
			       		} 
			       		
		       	       arr[j+1] = key; 
			} 
		}
		
		void insert(int val)
		{
			int flag = 0;
			arr = (int*)realloc(arr,++size);
			for(int i=0;i<size-1;i++)
			{
				if(arr[i] >= val)
				{
					for(int j=size-1;j>=i;j--)
					{
						arr[j+1] = arr[j];
					}
					arr[i] = val;
					flag = 1;
					break;
				}
			}
			
			if(flag == 0)
			{
				arr[size-1] = val;
			}
			
			
		}
		
		void display()
		{
			for(int i=0;i<size;i++)
			{
				cout<<arr[i]<<" ";
			};
			cout<<endl;
		}
};

int main()
{
	InsertionSort is;
	is.sort();
	cout<<"After Insertion Sort"<<endl;
	is.display();
	
	int num;
	
	cout<<"Enter a number to insert in array sequentially"<<endl;
	cin>>num;
	
	is.insert(num);
	is.display();
	
	return 0;
}
