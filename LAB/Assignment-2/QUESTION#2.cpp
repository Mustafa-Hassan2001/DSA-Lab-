#include <iostream>
#include<stdlib.h>
#include<string>

using namespace std;

struct Node{
	string data;
	Node* next;
	Node* prev;
};


class cicularParkinglot{	
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

int countnode(Node *ptr){
	int count=0;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}

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
//2
void deleteSpecific() { 
	int position;
	cout<<"Enter the position where you want to delete : ";
	cin>>position; 
  Node* nodeToDelete = head; 
  Node* temp = head;
  int NoOfElements = 0; // Find the number of elements in the list
  if(temp != NULL) {
    NoOfElements++;
    temp = temp->next;
  }
  while(temp != head) {
    NoOfElements++;
    temp = temp->next;
  }				// check if the specified position is valid
  if(position < 1 || position > NoOfElements) {
    cout<<"\nInavalid position.";
  } 
  else if (position == 1) {  
	if(head->next == head) {	 // if the position is 1 and head is the only
      head = NULL;		 //element in the list, then make it null, else make next  of head as new head and adjust links accordingly
    } 
	else {     
      while(temp->next != head)
        temp = temp->next;
      head = head->next;
      temp->next = head; 
      head->prev = temp;
      free(nodeToDelete); 
    }
  } else {
    temp = head;
    for(int i = 1; i < position-1; i++)
      temp = temp->next;
    nodeToDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    free(nodeToDelete); 
  }
}

void isEmpty(){		//Function to Check if the parking lot is empty
	Node*temp=head;
	if(head==NULL){
		cout<<"\nParking lot is Empty...Right Now!!";	
	}
	else{
		cout<<"\nParking lot is Not Empty...Right Now!!";
	}
}

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
//5
void insertAtEnd() {
	string newnumberplate;
    Node *ptr = new Node;  
    Node *temp;   
    cout<<"Enter the number plate of new car which you want to insert at the End of the parking lot :";
	cin>>newnumberplate;
    if(ptr == NULL)  
   {  
       cout<<"\nOVERFLOW";  
   }  
   else  
   {  
        ptr->data=newnumberplate;  
       if(head == NULL)  
       {  
           head = ptr;  
           ptr -> next = head;   
           ptr -> prev = head;   
       }  
       else  
       {  
          temp = head;  
          while(temp->next !=head)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          head -> prev = ptr;  
           ptr -> next = head;  
        }  
   }  
     cout<<"\nNode Inserted\n";  
}  

void delAtbig() {
  if(head != NULL) {
    if(head->next == head) { 	// the list contains one node, deletemake the head null
      head = NULL;
    } 
	else{  // if the list contains more than one node create two nodes - temp and firstNode, both pointing to head node
      Node* temp = head;
      Node* firstNode = head;
      while(temp->next != head) {	// using temp node, traverse to the last node
        temp = temp->next;
      }
      head = head->next;		// Make head as next of head, and update links
      head->prev = temp;
      temp->next = head; 
      free(firstNode); 
    }
  }
}
void display()
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
};

int main(){
		cicularParkinglot p1;
		int opt;
		p1.createList(3);
		cout<<endl;
		cout<<"\nThese Car are parked in Parking Lot : ";
		p1.display();
		cout<<endl;
	while(opt != 9){
		cout<<"\n\n 1-> Insert at Specific\n 2-> Delete at Specific \n 3-> Search Element \n 4-> Count all Element \n 5-> Insert At End \n 6-> Delete at End\n 7-> Delete at  Biggneng \n 7-> Check is Empty\n 9->Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>opt;
		switch(opt){
			case 1:
			p1.insertSpecific();
			cout<<"\nThese Car are parked in Parking Lot : ";
			p1.display();
			cout<<endl;
			break;
			case 2:
			p1.deleteSpecific();
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
			cout<<"\nTotal Numbers of cars parked in parking lot are : ";
			p1.countnode(p1.head);
			cout<<endl;
			break;
			case 5:
			p1.insertAtEnd();
			cout<<"\nThese Car are parked in Parking Lot : ";
			p1.display();
			cout<<endl;
			break;
			case 6:
			p1.delAtbig();
			cout<<"\nThese Car are parked in Parking Lot : ";
			p1.display();
			break;		
			case 7:
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

