#include<iostream>
using namespace std;

class binary_search
{
	int *array,size;
	
	public:
		void getData(int s)
		{
			size = s;
			array = new int[size];
			cout<<"Enter elements in array"<<endl;
			for(int i=0;i<size;i++)
			{
				cin>>array[i];
			}
		}
		
		void sort()
		{
			int temp;
			for(int i=0;i<size-1;i++)
			{
				for(int j=0;j<size-i-1;j++)
				{
					if(array[j]>array[j+1])
					{
						temp=array[j];
						array[j]=array[j+1];
						array[j+1]=temp;
					}
				}
			}
		}
		
		void find(int item)
		{
			int l=0,u=size-1,m;
   			
   			 while(l<=u)
	  		{
		 		m=(l+u)/2;
	     			if(item==array[m])
					{
		  				cout<<item<<" found at "<<m<<" index"<<endl;
		  				return;
					}
				else if(item>array[m])
					l=m+1;
				else
					u=m-1;

            		}
			cout<<item<<" not found"<<endl;
		}
		
		void show()
		{
			cout<<"After sorting"<<endl;
			for(int i=0;i<size;i++)
			{
				cout<<array[i]<<endl;
			}
		}
};

int main()
{
	binary_search l;
	int elem,size;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	l.getData(size);
	l.sort();
	l.show();
	cout<<"Enter element you want to search"<<endl;
	cin>>elem;
	l.find(elem);
	return 0;
}
