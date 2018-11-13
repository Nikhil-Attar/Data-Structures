#include<iostream>
using namespace std;

class hashing
{
	int* hash;
	int size;
	
	public:
	
		hashing(int size)
		{
			this->size = size;
			hash = new int[this->size];
			
			for(int i=0;i<size;i++)
				hash[i] = 0;
		}
		
		int Hash(int key)
		{
			return key%size;
		}
		
		void insert()
		{
			int key;
			for(int j=0;j<size;j++) {
			cin>>key;
			int loc = Hash(key);
			
			if(hash[loc] == 0)
				hash[loc] = key;
			else
			{
				for(int i=1;i<size;i++)
				{
					loc = ((key%size)+i)%size;
					if(hash[loc] == 0)
					{
						hash[loc] = key;
						break;
					}
				}
			}
			}
		}
		
		void display()
		{
			for(int i=0;i<size;i++)
			{
				cout<<i<<"\t"<<hash[i]<<endl;
			}
		}
		
};

int main()
{
	int size;
 	cout<<"Enter size of hash table"<<endl;
 	cin>>size;
 	hashing h(size);
 	h.insert();
 	h.display();
 	return 0;
}
