#include<iostream>
#include<stdlib.h>
using namespace std;
struct node {

	node *prev;
	int data;
	node *next;
};

class DLL {

	node *head;
	public:
	DLL() {

		head = NULL;

	}

	node* createnode(int val) {

		node *nn;
		nn = new node;
		nn->data = val;
		nn->prev = NULL;
		nn->next = NULL;
		return nn;
	}

	void insertatbeg(int val) {

		node *nn;
		nn = createnode(val);
		if(head == NULL) {

			head = nn;
		}
		else {
			nn->next = head;
			head->prev = nn;
			head = nn;
		}
	}

	void insertatend(int val) {

		node *nn;
		nn = createnode(val);
		if(head == NULL) {

			head = nn;
		}
		else {
			node *temp = head;
			while(temp->next!=NULL) {

				 temp = temp->next;
			}
			nn->prev = temp;
			temp->next = nn;
		}
	}

	void insertatloc(int val,int pos) {

		node *nn = createnode(val);
		if(head == NULL) {
			head = nn;
		}
		else if(head->next == NULL) {

			insertatend(val);
		}
		else {
			node *temp;
			temp = head;
			for(int i = 1;i < pos-1;i++) {

				temp = temp->next;
			}
			nn->next = temp->next;
			temp->next->prev = nn;
			temp->next = nn;
			nn->prev = temp;
		}
	}

	void traverse() {

		node *temp = head;
		while(temp != NULL) {

			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<endl;
	}

	void deleteatbeg() {

		if(head == NULL) {

			cout<<"Empty"<<endl;

		}
		else if(head->next == NULL) {

			node *ptr;
			ptr = head;
			head = NULL;
			delete (ptr);
		}
		else {

			node *ptr = head;
			head = ptr->next;
			head->prev = NULL;
			delete (ptr);
		}
	}

	void deleteatend() {

		if(head == NULL) {

			cout<<"Empty"<<endl;

		}
		else if(head->next == NULL) {

			deleteatbeg();
		}
		else {

			node *ptr = head;
			while(ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->prev->next = NULL;
			delete (ptr);
		}
	}

	void deleteatloc(int pos) {

		if(head == NULL) {

			cout<<"Empty"<<endl;

		}
		else if(head->next == NULL) {

			node *ptr;
			ptr = head;
			head = NULL;
			delete (ptr);
		}
		else {

			node *ptr = head;
			for(int i=1;i<pos-1;i++) {

				ptr = ptr->next;
			}
			ptr->next->next->prev = ptr;
			ptr->next = ptr->next->next;
			delete (ptr->next);
		}
	}

	void Delete(int val) {

		if(head == NULL) {

			cout<<"Empty"<<endl;

		}
		else {

			node *ptr = head;
			int i = 1;
			while(ptr->next != NULL) {

				if(ptr->data == val) {

					if(i == 1) {

						deleteatbeg();
						i = 1;
						ptr = head;
						traverse();
						continue;
					}
					else {

						deleteatloc(i);
						traverse();
						i--;
					}
				}
				i++;
				ptr = ptr->next;
			}
			if(ptr->data == val) {

				if(i == 1)
				{
					deleteatbeg();
					head = NULL;
				}
				else
					deleteatend();
			}
		}
	}

	void Search(int ele) {

		node *temp = head;
		while(temp != NULL) {

			if(temp->data == ele)
				break;
			temp = temp->next;
		}

		if(temp == NULL)
			cout<<"Element not found"<<endl;
		else
			cout<<"Element found"<<endl;
	}
};

int main()
{
	DLL dll;
	int choice,num;
	while(true) {
		cout<<"1. Insert element at beginning"<<endl;
		cout<<"2. Insert element at end"<<endl;
		cout<<"3. Insert element at a particular location"<<endl;
		cout<<"4. Delete an existing element"<<endl;
		cout<<"5. Search the doubly linked list"<<endl;
		cout<<"6. Display doubly linked list"<<endl;
		cout<<"7. Exit"<<endl;
		
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice) {

			case 1: cout<<"Enter a number to insert at beginning:"<<endl;;
				cin>>num;
				dll.insertatbeg(num);
				break;

			case 2: cout<<"Enter a number to insert at end:"<<endl;
				cin>>num;
				dll.insertatend(num);
				break;

			case 3: int pos;
				cout<<"Enter a number to insert at a particular location:"<<endl;
				cin>>num;
				cout<<"Enter a position:"<<endl;
				cin>>pos;
				dll.insertatloc(num,pos);
				break;

			case 4:	cout<<"Enter number to delete:"<<endl;
				cin>>num;
				dll.Delete(num);
				break;

			case 5: cout<<"Enter number to search in the Doubly Linked List"<<endl;
					cin>>num;
					dll.Search(num);
					break;

			case 6: cout<<"Doubly linked list:"<<endl;
				dll.traverse();
				break;

			case 7:
				exit(0);
				
			default: cout<<"Invalid Choice"<<endl;
		}
	}
	return 0;
}


