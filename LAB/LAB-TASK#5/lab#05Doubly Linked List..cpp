#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* prev;
};

Node* head=NULL;
Node* tail=NULL;

void createList(int n){
	int val;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the data value of node : ";
		cin>>val;
		Node *newNode=(Node*)malloc(sizeof(Node*));
		newNode->data=val;
		newNode->prev=NULL;
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
			newNode->prev=temp;
			newNode->prev=NULL;		
		}
		
	}
}

int countnode(Node *ptr){
	int count=0;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}
void displayForward()
{
	Node*temp=head;
	if(head==NULL)
	{
		cout<<"Linked List is Empty!!";
		
	}
	else{
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
	cout<<endl;
}

void insertFromHead(){
	Node* nN=(Node*)malloc(sizeof(Node*));
	int nval;
	cout<<"Enter the value of new node : "<<endl;
	cin>>nval;
	nN->data=nval;
	nN->next=NULL;
	if(head==NULL){
		head=nN;	
	}
	else{
			nN->next=head;
			head=nN;
	}
}

void insertFromTail(){
	Node *prev;
	int n;
	Node* nNew=(Node*)malloc(sizeof(Node*));
	cout<<"Enter the value which is going to insert at the End : ";
	cin>>n;
	nNew->data=n;
	nNew->next=NULL;
	if(head==NULL)
	{
		cout<<"Linked List is Empty!!"<<endl;
		head=nNew;
		
	}
	else{
		prev=head;
		while(prev->next!=NULL)
		{
			prev=prev->next;
		}
		prev->next=nNew;	
	}
}

void deletFromHead(){
	Node* temp;
	if(head==NULL){
		cout<<"The Linked List is Empty!!"<<endl;
	}
	else{
			temp=head;
			head=temp->next;
			free(temp);	
	}
}

void deletFromTail(){
	Node* temp,*curr;
	if(head==NULL)
	{
		cout<<"The Linked List is Empty"<<endl;
		
	}
	else{
			temp=head;
			curr=head;
			while(temp->next!=NULL)
			{
				curr=temp;
				temp=temp->next;
				
			}
			curr->next=NULL;
		}
		free(temp);
}

void InsertatGivenLocation() {
	int newElement, position;
	cout<<"Enter the position where you want to enter : ";
	cin>>position;  
	cout<<"Enter the value which you want to enter : ";
	cin>>newElement;    
  Node* newNode = new Node(); 
  newNode->data = newElement;
  newNode->next = NULL;
  newNode->prev = NULL;
  if(position < 1) {
    cout<<"\nposition should be >= 1.";
  } else if (position == 1) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  } else {
    Node* temp = head;
    for(int i = 1; i < position-1; i++) {
      if(temp != NULL) {
        temp = temp->next;
      }
    }
    if(temp != NULL) {
      newNode->next = temp->next;
      newNode->prev = temp;
      temp->next = newNode;
      if(newNode->next != NULL)
        newNode->next->prev = newNode;  
    } else {
      cout<<"\nThe previous node is null.";
    } 
  }
}

void DeletefromGivenLocation() {  
	int position;
	cout<<"Enter the position where you want to enter : ";
	cin>>position;   
	cout<<endl;
  if(position < 1) {
    cout<<"\nposition should be >= 1.";
  } else if (position == 1 && head != NULL) {
    Node* nodeToDelete = head;
    head = head->next;
    free(nodeToDelete);
    if(head != NULL)
      head->prev = NULL;
  } else {
    Node* temp = head;
    for(int i = 1; i < position-1; i++) {
      if(temp != NULL) {
        temp = temp->next;
    }
}
    if(temp != NULL && temp->next != NULL){
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        if(temp->next->next != NULL)
          temp->next->next->prev = temp->next;  
        free(nodeToDelete); 
    } else {
      cout<<"\nThe node is already null.";
    }       
  }
} 

void DISPLAY_BACWARDS(){
	Node *temp=head;
	if(head==NULL)
	{
		cout<<"Linked List is Empty!!";
		
	}
	else{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp->prev!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->prev;
		}
			cout<<temp->data;		
	}
	cout<<endl;
}
                      
int main(int argc, char** argv) {
	int opt;
	createList(4);
	cout<<"Your Link List is : "<<endl;
	displayForward();
	cout<<endl;
	cout<<endl;
	do {
	cout<<"-----------------------------"<<endl;
	cout<<"1->Insert From Head "<<endl;
	cout<<"2->Insert From Tail "<<endl;
	cout<<"3->Delet From Head "<<endl;
	cout<<"4->Delet From Tail "<<endl;
	cout<<"5->Insert at Given Location"<<endl;
	cout<<"6->Delet From Given Location"<<endl;
	cout<<"7->DISPLAY BACWARDS"<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<"Enter your Choice : ";
	cin>>opt;
	cout<<endl;
	switch(opt){
		case 1:
		insertFromHead();
		displayForward();
		break;			
		case 2:
		insertFromTail();
		displayForward();
		break;
		case 3:
		deletFromHead();
		displayForward();
		break;		
		case 4:
		deletFromTail();
		displayForward();
		break;			
		case 5:
		InsertatGivenLocation();
		displayForward();
		break;
		case 6:
		DeletefromGivenLocation();
		displayForward();
		break;
		case 7:
		DISPLAY_BACWARDS();
//		displayForward();
		break;	
//		exit(8);	
	}
	}while(opt!=4);

	
	
	

	return 0;
}
