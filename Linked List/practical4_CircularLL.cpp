#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	node *next;
};

class CLL
{
	node *head;
	public:
	CLL() {

		head = NULL;
	}

	void createnode(int val) {

		node *n;
		n = (node*)malloc(sizeof(node));
		n->data = val;
		n->next = n;
		head = n;
	}

	void insertatbeg(int val) {

		if(head == NULL)
			createnode(val);
		else
		{
			node * firstnode,* lastnode;
			firstnode = (node*)malloc(sizeof(node));
			lastnode = head;
			while(lastnode->next!=head)
				lastnode = lastnode->next;
			firstnode->data = val;
			firstnode->next = head;
			lastnode->next = firstnode;
			head = firstnode;
		}
	}

	void insertatend(int val)
	{
		node *ptr,*nn;
		nn = (node*)malloc(sizeof(node));
		nn->data = val;
		ptr = head;
		while(ptr->next!=head)
			ptr = ptr->next;
		ptr->next = nn;
		nn->next = head;
	}
	void traverse() {

		struct node *cur;
		cur = head ;
		if(head == NULL)
			cout<<"Empty Circular Linked List"<<endl;
		else
		{
			do {
				cout<<cur->data<<"\t";
				cur = cur->next;
			}while(cur!=head);
			cout<<endl;
		}
	}

	void insertatloc(int val,int loc)
	{
		node *ptr,*nn;
		nn = (node*)malloc(sizeof(node));
		ptr = head;
		for(int i = 1;i < loc-1 && ptr!=NULL;i++)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
			cout<<"Location doesn't exist"<<endl;
		else {
			nn->data = val;
			nn->next = ptr->next;
			ptr->next = nn;
		}
	}
	void deletefrombeg()
	{
		node *temp,*ptr;
		temp = head;
		ptr = head;
		if(head->next == head)
			head = NULL;
		else {
			while(ptr->next!=head)
				ptr = ptr->next;
			ptr->next = head->next;
			head = ptr->next;
		}
		delete (temp);
	}
	void deletefromend()
	{
		node *ptr,*prev;
		ptr = head;
		while(ptr->next!=head)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = head;
		delete (ptr);
	}
	void deleteatloc(int loc)
	{
		node *ptr,*prev;
		ptr = head;
		for(int i = 1;i < loc;i++)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		prev->next = ptr->next;
		delete (ptr);
	}
	void Delete(int item)
	{
		node *ptr;
		ptr = head;
		int i = 1;
		if(ptr->data == item) {

			deletefrombeg();
		}
		else {
			ptr = ptr->next;
			while(ptr!=head)
			{
				if(ptr->data == item)
				{
					if(ptr->next == head) {
						deletefromend();
						break;
					}
					else
					{
						deleteatloc(i);
						break;
					}
				}
				i++;
				ptr = ptr->next;
			}
		}
	}
	void Search(int val) {

		node *cur = head;
		int flag = 0;
		
		if(head == NULL)
			cout<<"Empty Circular Linked List"<<endl;
		else
		{
			do {
				if(cur->data == val) {

					flag = 1;
					break;
				}
				cur = cur->next;
			}while(cur!=head);
			if(flag == 1)
				cout<<"Element found"<<endl;
			else
				cout<<"Element not found"<<endl;
		}
	}
};

int main()
{
	CLL cll;
	int choice,num;
	while(true) {
		cout<<"1. Insert element at beginning"<<endl;
		cout<<"2. Insert element at end"<<endl;
		cout<<"3. Insert element at a particular location"<<endl;
		cout<<"4. Delete an existing element"<<endl;
		cout<<"5. Search the Circular linked list"<<endl;
		cout<<"6. Display Circular linked list"<<endl;
		cout<<"7. Exit"<<endl;
		
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice) {

			case 1: cout<<"Enter a number to insert at beginning:"<<endl;
				cin>>num;
				cll.insertatbeg(num);
				break;

			case 2: cout<<"Enter a number to insert at end:"<<endl;
				cin>>num;
				cll.insertatend(num);
				break;

			case 3: int pos;
				cout<<"Enter a number to insert at a particular location:"<<endl;
				cin>>num;
				cout<<"Enter a position:"<<endl;
				cin>>pos;
				cll.insertatloc(num,pos);
				break;

			case 4:	cout<<"Enter number to delete:"<<endl;
				cin>>num;
				cll.Delete(num);
				break;

			case 5: cout<<"Enter number to search in the Circular Linked List"<<endl;
					cin>>num;
					cll.Search(num);
					break;

			case 6: cout<<"Circular linked list:"<<endl;
				cll.traverse();
				break;

			case 7: 
				exit(0);
				
			default: cout<<"Invalid Choice"<<endl;
		}

	}
	return 0;
}

