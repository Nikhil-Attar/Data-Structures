#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {

	node *left;
	int data;
	node *right;
} *root;

class bst
{
	int *ptr;
	public:
	
		bst()
		{
			root = NULL;
			ptr = NULL;
		}
		
		node* insert(node *ptr,int num)
		{
			if(ptr == NULL) 
			{
				node *newnode = new node();
				newnode->data = num;
				newnode->left = NULL;
				newnode->right = NULL;
				root = newnode;
				cout<<"Root node inserted\n";
				ptr = root;
			}
			else
			{
				if(ptr->data < num)
				{
					if(ptr->right!=NULL)
					{
						insert(ptr->right,num);
					}
					else
					{
						node *newnode = new node();
						newnode->data = num;
						ptr->right = newnode;
						newnode->left = NULL;
						newnode->right = NULL;
						cout<<"Node inserted at right"<<endl;
					}
				}
				else if(ptr->data > num)
				{
					if(ptr->left!=NULL)
					{
						insert(ptr->left,num);
					}
					else
					{
						node *newnode = new node();
						newnode->data = num;
						ptr->left = newnode;
						newnode->left = NULL;
						newnode->right = NULL;
						cout<<"Node inserted at left"<<endl;
					}
				}
				else
				{
				cout<<"The node is already present"<<endl;
				}
			}
		}
		
		node* deletenode(node* ptr,int key)
		{
			if(ptr==NULL)
			{
				return ptr;
			}
				
			 if(ptr->data>key)
			{
				ptr->left = deletenode(ptr->left,key);
			}
			else if(ptr->data<key)
			{
				ptr->right = deletenode(ptr->right,key);
			}
			else
			{
				if(ptr->left==NULL)
				{
					struct node* temp = ptr->right;
					delete ptr;
					return temp;
				}
				else if(ptr->right==NULL)
				{
					struct node* temp = ptr->left;
					delete ptr;
					return temp;
				}
				
				
					struct node* succ = inordersucc(ptr->right);
					ptr->data = succ->data;
					ptr->right = deletenode(ptr->right,succ->data);
			}
			return ptr;
		}

		node* inordersucc(node* ptr)
		{
			while(ptr->left!=NULL)
			{
				ptr = ptr->left;
			}
			return ptr;
		}
		
		void inorder(node* p)
		{
			if(p == NULL)
				return;
			else
			{
				inorder(p->left);
				cout<<p->data<<" ";
				inorder(p->right);
			}
		}
		
		void postorder(node* p)
		{
			if(p == NULL)
				return;
			else
			{
				postorder(p->left);
				postorder(p->right);
				cout<<p->data<<" ";
			}
		}
		
		void preorder(node* p)
		{
			if(p == NULL)
				return;
			else
			{
				cout<<p->data<<" ";
				preorder(p->left);
				preorder(p->right);
			}
		}
};

int main()
{
	bst b;
	int choice,num;
	
	while(true)
	{
		cout<<"1. Insert a new element"<<endl;
		cout<<"2. Delete an existing element"<<endl;
		cout<<"3. Traverse the tree"<<endl;
		cout<<"4. Exit"<<endl;
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter element"<<endl;
				cin>>num;
				b.insert(root,num);
				break;
				
			case 2:
				cout<<"Enter element"<<endl;
				cin>>num;
				b.deletenode(root,num);
				break;
				
			case 3:
				cout<<"1. Pre-order Traversal"<<endl;
				cout<<"2. In-order Traversal"<<endl;
				cout<<"3. Post-order Traversal"<<endl;	
				cin>>num;
				
				if(num == 1)
					b.preorder(root);
				else if(num == 2)
					b.inorder(root);
				else if(num == 3)
					b.postorder(root);
				cout<<endl;	
				break;
			
			case 4:
				exit(0);
				
			default:
				cout<<"Invalid Choice"<<endl;
		}
	}

	return 0;
}
