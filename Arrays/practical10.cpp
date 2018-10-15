#include<iostream>
using namespace std;

class SortAndMerge
{
	public:
	
		void getData(int arr[], int size)
		{
			cout<<"Enter elements"<<endl;
			for(int i=0;i<size;i++)
			{
				cin>>arr[i];
			}
		}
		
		void merge(int arr[], int l, int m, int r) 
		{ 
    			int i, j, k; 
    			int n1 = m - l + 1; 
    			int n2 =  r - m; 
  
    			int L[n1], R[n2]; 
  
    			for (i = 0; i < n1; i++) 
        			L[i] = arr[l + i]; 
    			for (j = 0; j < n2; j++) 
        			R[j] = arr[m + 1+ j]; 

    			i = 0; 
    			j = 0; 
    			k = l; 
    			
    			while (i < n1 && j < n2) 
    			{ 
        			if (L[i] <= R[j]) 
        			{	 
            				arr[k] = L[i]; 
            				i++; 
        			} 
        			else
        			{ 
            				arr[k] = R[j]; 
            				j++; 
        			} 
        				k++; 
    			} 
  
    			while (i < n1) 
    			{ 
        			arr[k] = L[i]; 
        			i++; 
        			k++; 
    			} 
  
    		while (j < n2) 
    		{		 
        		arr[k] = R[j]; 
        		j++; 
        		k++; 
    		} 
	} 
  
	void mergeSort(int arr[], int l, int r) 
	{	 
    		if (l < r) 
    		{  
        		int m = l+(r-l)/2; 
        		mergeSort(arr, l, m); 
        		mergeSort(arr, m+1, r); 
  
        		merge(arr, l, m, r); 
    		} 
	} 
		
		void selectionSort(int arr[],int size) 
		{ 
		    int i,j,index; 
  
		    for (i=0;i<size-1;i++) 
		    { 
		        index = i; 
		        for (j=i+1;j<size;j++) 
		        {
		         	 if (arr[j] < arr[index]) 
		         	 {
		            		index = j; 
		            	 }
		        }

		        	int temp;
		        	temp = arr[index];
		        	arr[index] = arr[i];
		        	arr[i] = temp;
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
	int *arr1,*arr2,*arr3;
	int size1,size2,size3;
	
	SortAndMerge sm;
	
	cout<<"Enter the size of first array"<<endl;
	cin>>size1;
	arr1 = new int[size1];
	sm.getData(arr1,size1);
	
	cout<<"Enter the size of second array"<<endl;
	cin>>size2;
	arr2 = new int[size2];
	sm.getData(arr2,size2);
	
	sm.selectionSort(arr1,size1);
	sm.selectionSort(arr2,size2);
	
	cout<<"After Selection Sort on first array"<<endl;
	sm.display(arr1,size1);
	
	cout<<"After Selection Sort on second array"<<endl;
	sm.display(arr2,size2);
	
	size3 = size1+size2;
	arr3 = new int[size3];
	
	int index = 0;
	
	for(int i=0;i<size1;i++)
	{
		arr3[index] = arr1[i];
		index++;
	}
	
	for(int j=0;j<size2;j++)
	{
		arr3[index] = arr2[j];
		index++;
	}
	
	cout<<"After merging two arrays"<<endl;
	sm.display(arr3,size3);
	
	sm.mergeSort(arr3,0,size3-1);
	
	cout<<"After merge sort"<<endl;
	sm.display(arr3,size3);
	
	return 0;
}
