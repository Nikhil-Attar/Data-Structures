#include<iostream>
using namespace std;

class linear_search
{
	int *array,size,flag,pos;
	
	public:
		void getData(int s)
		{
			size = s;
			array = new int[size];
			cout<<"Enter elements"<<endl;
			for(int i=0;i<size;i++)
			{
				cin>>array[i];
			}
		}
		
		void Search(int elem)
		{
			flag=0;
			for(int i=0;i<size;i++)
			{
				if(elem==array[i])
				{
					flag=1;
					pos=i;
					break;
				}
			}
			if(flag==1)
			{
				cout<<"Element found at "<<pos<<" index"<<endl;
			}
			else
			{
				cout<<"Element not found"<<endl;
			}
		}
};

int main()
{
	linear_search l;
	int elem,size;
	
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	
	l.getData(size);
	
	cout<<"Enter element you want to search"<<endl;
	cin>>elem;
	
	l.Search(elem);
	
	return 0;
}
