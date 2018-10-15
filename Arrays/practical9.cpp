#include<iostream>
using namespace std;

class QuickSort
{	
	public:
		
		int partition (int arr[],int low,int high) 
		{ 
			int temp;
    			int pivot = arr[high];   
			int i = (low - 1);  
  
			    for (int j=low;j<=high-1;j++) 
			    {  
			        if (arr[j] <= pivot) 
			        { 
			            i++;    
			            //swap(&arr[i],&arr[j]); 
			            temp = arr[i];
			            arr[i] = arr[j];
			            arr[j] = temp;
			        } 
			    } 
		    //swap(&arr[i + 1], &arr[high]); 
		    temp = arr[i+1];
		    arr[i+1] = arr[high];
		    arr[high] = temp;
		    
		    return i+1; 
		} 
		
		void quickSort(int arr[],int low,int high)
		{
			if (low < high)
			{
        			int pi = partition(arr, low, high); 
			        quickSort(arr,low,pi-1); 
		        	quickSort(arr,pi+1,high); 
    			} 
		}
		
		void display(int arr[],int size)
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
	int *arr,size;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	arr = new int[size];
			
	cout<<"Enter elements"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	QuickSort qs;
	qs.quickSort(arr,0,size-1);
	
	cout<<"After Quick Sort"<<endl;
	qs.display(arr,size);
	
	return 0;
}
