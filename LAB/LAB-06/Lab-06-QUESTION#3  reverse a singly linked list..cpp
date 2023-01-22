#include<iostream>
#include<stdlib.h>

using namespace std;
struct Node{
	int data;
	Node* next;
};

Node* head=NULL;
//A
void createList(int n){
	int numberplate;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the number : ";
		cin>>numberplate;
		Node *newNode=(Node*)malloc(sizeof(Node*));
		newNode->data=numberplate;
		newNode->next=NULL;
		if(head==NULL)
		{
			head=newNode;
		}
		else{
			Node* temp=head;
			while(temp->next!=NULL)
			{
				
				temp=temp->next;
				
			}
			temp->next=newNode;
		}	
	}
}

void reverse(){
        Node* current = head;
        Node *prev = NULL, *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
 }

//Display the link list data
void display(){
	Node*temp=head;
	if(head==NULL)
	{
		cout<<"Parking lot is Empty";
		
	}
	else{
		cout<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}	
}

int main(){
	createList(4);
	display();
	reverse();
	cout<<"\nReverse Link List :"<<endl;
	display();
	return 0;
}
