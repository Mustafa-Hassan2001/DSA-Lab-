#include <iostream>
#include<stdlib.h>
#include<string>
///* runce this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Node{
//(a)	
	string data;
	Node* next;
	Node* prev;
};


class car{	
	public:
Node* next = NULL;
Node* prev = NULL;
Node* head = NULL;

void createList(int n){
	string numberplate;
	for(int i=0;i<n;i++){
		cout<<"Enter the number plate to park : ";
		cin>>numberplate;
		Node *newNode=new Node;
		newNode->data=numberplate;
		newNode->prev=NULL;
		newNode->next=NULL;
		if(head==NULL)
		{
			head=newNode;
		}
		else{
			Node* temp=head;
			while(temp->next!=NULL){	
				temp=temp->next;
			}
			temp->next=newNode;	
			newNode->prev=temp;
			newNode->prev=NULL;		
		}
	}
}
//(g)
int countnode(Node *ptr){
	int count=0;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}

//(b)
void insertAtEnd(){
    string val;
    Node*tempd;
    Node* newNode=new Node ;
    cout<<endl<<"Enter the value of new node to insert at end : ";
    cin>>val;
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else{
        tempd=head;

        while(tempd->next!=NULL)
        {
            tempd=tempd->next;
        }
        tempd->next=newNode;
        newNode->prev=tempd;
    }
}
//(c)
int RemoveSpecific(){
	int position;
	cout<<"Enter the Position ";
	cin>>position;
	if(position < 1){
		cout<<"Position not Aviable "<<endl;
	}
	else if( position == 1 && head != NULL){
		Node * nN = head;
		head = head->next;
		free(nN);
	}
	if(head != NULL){
		head->prev=NULL;
	}
	else{
		Node *temp = head;
		for(int i=1; i<position-1; i++){
			if(temp!=NULL){
				temp = temp->next;
			}
		}
		if(temp!=NULL&&temp->next!=NULL){
			Node * nodetodelete = temp->next;
			temp->next = temp->next->next;
			if(temp->next->next!=NULL){
				temp->next->next->prev = temp->next;
			free(nodetodelete);	
			}
			else{
				cout<<"The Node is Already Null";
			}
		}
	}
}
//(d)
void insertSpecific() {
	int position;
	string newnumplate;
	cout<<"Enter the position where you want to enter : ";
	cin>>position;  
	cout<<"Enter the value which you want to enter : ";
	 cin>>newnumplate;    
  Node* newNode = new Node(); 
  newNode->data = newnumplate;
  newNode->next = NULL;
  newNode->prev = NULL;
  if(position < 1) {
    cout<<"\nposition should be >= 1.";
  } 
  else if (position == 1) {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
  else {
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
    } 
	else {
      cout<<"\nThe previous node is null.";
    } 
  }
}
//(e)
void isEmpty(){		//Function to Check if the parking lot is empty
	Node*temp=head;
	if(head==NULL){
		cout<<"\nParking lot is Empty...Right Now!!";	
	}
	else{
		cout<<"\nParking lot is Not Empty...Right Now!!";
	}
}
//(f)
void SearchElement(){
  Node* temp = head;		// create a temp node pointing to head
  string searchnumberplate;		
  int found = 0;
  int i = 0;
  	cout<<"Enter the number plate of particular car to check it is in Parking Lot or not  :";
	cin>>searchnumberplate;
  if(temp != NULL) {	 // If the temp node is not null check thE node value with searchValue, if found update variables and 
    while(true) {		// break the loop, else  continue searching till temp node is not head
      i++;
      if(temp->data == searchnumberplate) {
        found++;
        break;
      }
      temp = temp->next;
      if(temp == head) {break;}     
    }
    if (found == 1) {
      cout<<searchnumberplate<<" is found at index = "<<i<<".\n";
    } else {
      cout<<searchnumberplate<<" is not found in the list.\n";
    }
  } 
  else{
    cout<<"The list is empty.\n";	// If the temp node is null at the start,the list is empty
  }
} 

void display(){	
	Node*temp=head;
	if(head==NULL){
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
};

int main(){
		car p1;
		int opt;
		p1.createList(3);
		cout<<endl;
		cout<<"\nThese Car are parked in Parking Lot : ";
		p1.display();
		cout<<endl;
	while(opt != 6){
		cout<<"\n\n 1-> insert At End\n 2-> Remove at Specific \n 3-> Search Element \n 4-> Count all Element \n 5-> Check is Empty\n 6->Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>opt;
		switch(opt){
			case 1:
			p1.insertAtEnd();
			cout<<"\nThese Car are parked in Parking Lot : ";
			p1.display();
			cout<<endl;
			break;
			case 2:
			p1.RemoveSpecific();
			cout<<"\nThese Car are parked in Parking Lot : ";
			p1.display();
			cout<<endl;
			break;
			case 3:
			p1.SearchElement();
			cout<<"\nThese Car are parked in Parking Lot : ";
			p1.display();
			cout<<endl;
			break;
			case 4:
			cout<<"\nTotal Numbers of cars parked in parking lot are : "<<p1.countnode(p1.head);
			cout<<endl;
			break;		
			case 5:
			p1.isEmpty();
			break;	
			case 0:
			break;
			default:
			cout<<"\nIncorrect Choice";	
		}
	}
return 0;
}

