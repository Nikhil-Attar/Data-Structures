#include <iostream>
using namespace std;

class Heap_Sort
{
	public:
	
		void heapify(int arr[], int n, int i)
		{
   			int largest = i;
   			int l = 2*i + 1;
   			int r = 2*i + 2;

   			if (l<n && arr[l] > arr[largest])
   			{
     				largest = l;
			}
			
   			if (r<n && arr[r] > arr[largest])
   			{
     				largest = r;
			}
			
   			if (largest != i)
   			{		
     				swap(arr[i], arr[largest]);
     				heapify(arr, n, largest);
   			}
		}

		void heapSort(int arr[], int n)
		{
   			for (int i = n / 2 - 1; i >= 0; i--)
   			{
     				heapify(arr, n, i);
			}
			
   			for (int i=n-1; i>=0; i--)
   			{
     				swap(arr[0], arr[i]);
     				heapify(arr, i, 0);
   			}
		}

		void display(int arr[], int n)
		{
   			for (int i=0; i<n; ++i)
   			{
     				cout<<arr[i]<<" ";
   			}
   			
   			cout<<endl;
		}
};

int main()
{
	Heap_Sort hs;
	cout<<"Enter size of array"<<endl;
	int n;
	cin>>n;
	int arr[n];
   
	cout<<"Enter elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
   
	hs.heapSort(arr, n);

	cout<<"Array after heap sort"<<endl;
	hs.display(arr, n);
   
	return 0;
}
