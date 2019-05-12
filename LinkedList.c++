#include<iostream>
#include<stdio.h>   // for getchar()
#include<stdlib.h>   // for system(clear)
using namespace std;

class LinkedList;

class Node{
    int data;
    Node * next = NULL;
    friend LinkedList;
};

class LinkedList{
	Node * start = NULL;
	public:

	LinkedList(){
		//createNode();
	}

	void createLinkedList(){
    	if(start == NULL){
    	    cout<<"Creating LinkedList:\n";
    		start = new Node();
    		cout<<"Enter the value for 1st Element: ";
    		cin>>start->data;
    	}else{
    		cout<<"Linked List Already created!!"<<endl;
    	}
		print();
    }

    void insertAtFirst(){
    	if(start == NULL){
    		createLinkedList();
    	}else{
	        cout<<"Inserting node at First position :\n";
	        Node * ptr = new Node;
	        cout<<"Enter the value for new node: ";
		    cin>>(ptr->data);
		    ptr->next = start;
		    start = ptr;
				print();
    	}
    }

	void insertAtLast(){
		if(start == NULL){
    		createLinkedList();
    	}else{
    		cout<<"Inserting Node at last position :\n";
		    Node * last = new Node;
		    cout<<"Enter the value for new node: ";
		    cin>>(last->data);
		    Node * ptr = start;
		    while (ptr->next != NULL)
	            ptr = ptr->next;
	      ptr->next = last;
				print();
    	}
	}

	void insertAfter(){
		if(start == NULL){
    		createLinkedList();
    	}else{
			int x = 0;
			cout<<"Enter Node Element to insert After: ";
			cin>>x;
			cout<<"Inserting NEW node After "<<x<<" Element :\n";
			Node * ptr = start;
			while(ptr->data != x){
				ptr = ptr->next;
				if(ptr==NULL){
					cout<<"Element Not FOUND"<<endl;
					pauseScreen();
					return;
				}
			}
			Node * newNode = new Node;
			cout<<"Enter the value for new node: ";
			cin>>(newNode ->data);
			newNode->next = ptr->next;
			ptr->next = newNode;
			print();
		}
	}

	void deleteFirst(){
		if(start == NULL){
			cout<<"Linked List Not Created !"<<endl;
			pauseScreen();
		}else{
			cout<<"Deleting First Node: \n";
			Node * ptr = start;
			start = ptr->next;
			ptr->next = NULL;
			delete ptr;
			print();
		}
	}

	void deleteLast(){
		if(start == NULL){
			cout<<"Linked List Not Created !"<<endl;
			pauseScreen();
		}else{
			cout<<"Deleting Last Node: \n";
			Node * ptr = start;
			Node * prev;
			if(start -> next == NULL){
				start = NULL;
			}else{
				while(ptr->next != NULL){
					prev = ptr;
					ptr = ptr->next;
				}
				prev->next = NULL;
				ptr->next = NULL;
				delete ptr;
			}
			print();
		}
	}

	void deleteNode(){
		if(start == NULL){
			cout<<"Linked List Not Created !"<<endl;
			pauseScreen();
		}else{
			cout<<"Deleting Node with given value"<<": \n";
			int x;
			cout<<""<<endl;
			cout<<"Enter node value to delete: ";
			cin>>x;
			Node * ptr = start;
			Node * prev;
			if(start -> data == x){
				start = start->next;
			}else{
				while(ptr->data != x){
					prev = ptr;
					ptr = ptr->next;
					if(ptr==NULL){
						cout<<"Node with value "<<x<<" not found"<<endl;
						pauseScreen();
						return;
					}
				}
				prev->next = ptr->next;
				ptr->next = NULL;
				delete ptr;
			}
			print();
		}
	}

	void deleteEvenValueNode(){
		if(start == NULL){
			cout<<"Linked List Not Created !"<<endl;
			pauseScreen();
		}else{
			cout<<"Deleting ALL Even Value Nodes: \n";
			Node * ptr = start;
			Node * prev;
			while(ptr != NULL){
				if(start->data % 2 ==0){
					start = start->next;
					delete ptr;
					ptr = start;
				}else if(ptr->data % 2 ==0){
					prev->next = ptr->next;
					delete ptr;
					ptr = prev->next;
				}else{
					prev = ptr;
					ptr = ptr->next;
				}
			}
			print();
		}
	}

	void deleteLinkedList(){
		cout<<"Deleting Linked List: \n";
		start = NULL;
		pauseScreen();
	}

	void reverse(){
		if(start == NULL){
			cout<<"Linked List Not Created !"<<endl;
			pauseScreen();
		}else{
			// Doing it my way
			cout<<"Reversing Linked List (Linked List):\n";
			Node * head = NULL;
			Node * ptr = start;
			Node * prev = NULL;
			while(ptr->next != NULL)
				ptr = ptr->next;
			head = ptr;
			while(start != head){
				ptr = start;
				while(ptr->next != NULL){
					prev = ptr;
					ptr = ptr->next;
				}
				if(ptr == start){
					start = head;
				}else{
					ptr->next = prev;
					prev->next = NULL;
				}
			}
			print();
		}
	}

	void Reverse(){
		if(start == NULL){
			cout<<"Linked List Not Created !"<<endl;
			pauseScreen();
		}else{
			// Geeks Way of doing
			cout<<"Reversing Linked List (Doing it GEEKS way):\n";
			Node * cur = start;
			Node * next = NULL;
			Node * prev = NULL;
			while(cur != NULL){
				next = cur->next;
				cur->next = prev;
				prev = cur;
				cur = next;
			}
			start = prev;
			print();
		}
	}


	void print(){
	    if(start == NULL){
	    	cout<<"Nothing to print\nCreate Linked List First !"<<endl;
			pauseScreen();
	    	return ;
	    }else{
			cout<<"Printing Linked List:\n";
	    	Node * ptr = start;
			while(ptr!=NULL){
				cout<<(ptr->data)<<"\n";
				ptr=ptr->next;
			}
			pauseScreen();
		}
	}

	void pauseScreen(){
		cout<<"\nPress any key to continue";
		getchar();
		getchar();
	}
};

int main(){

	int choice;
	bool flag = true;

	LinkedList ll;

	system("cls");

	do {

		system("cls");

		cout<<"\t\t\t  ** Linked List ** "<<endl<<endl;
		cout<<"\tMain Menu"<<endl;
		cout<<"1.  Create Linked List"<<endl;
		cout<<"2.  Insert Node at Front Position"<<endl;
		cout<<"3.  Insert Node at Last Position"<<endl;
		cout<<"4.  Insert Node after Element Value"<<endl;
		cout<<"5.  Delete Node from Front Position"<<endl;
		cout<<"6.  Delete Node from Last Position"<<endl;
		cout<<"7.  Delete Node By Element Value"<<endl;
		cout<<"8.  Delete All Nodes with EVEN Node Elements"<<endl;
		cout<<"9.  Reverse Linked List (Doing it my way)"<<endl;
		cout<<"10. Reverse Linked List (Doing it GEEKS way)"<<endl;
		cout<<"11. Print Linked List"<<endl;
		cout<<"77. Delete Linked List"<<endl;
		cout<<"99. Exit"<<endl;

		cout<<"\n\tEnter your choice: ";
		cin>>choice;

		switch (choice)
		{
		case 1:
			ll.createLinkedList();
			break;
		case 2:
			ll.insertAtFirst();
			break;
		case 3:
			ll.insertAtLast();
			break;
		case 4:
			ll.insertAfter();
			break;
		case 5:
			ll.deleteFirst();
			break;
		case 6:
			ll.deleteLast();
			break;
		case 7:
			ll.deleteNode();
			break;
		case 8:
			ll.deleteEvenValueNode();
			break;
		case 9:
			ll.reverse();
			break;
		case 10:
			ll.Reverse();
			break;
		case 11:
			ll.print();
			break;
		case 77:
			ll.deleteLinkedList();
			break;
		case 99:
			system("cls");

			cout<<"\n\n\tThanks for using this program"<<endl
			<<"\n\tMade By - Lokesh Sarathe";

			getchar();getchar();

			flag = false;
			break;

		default:
			cout<<"\n\n\tEnter CORRECT choice."<<endl;
			getchar();getchar();
			break;
		}

	}while(flag);

	return 0;
}
