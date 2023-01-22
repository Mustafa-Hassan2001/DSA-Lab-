#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
struct Node{
	string data;
	Node* next;
};


class cicularParkinglot{
public:
Node* head=NULL;
//	Function to  create list 
void createList(int n){
	string numberplate;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the number plate to park : ";
		cin>>numberplate;
		Node *newNode=new Node;
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
			newNode = temp;
		}	
	}
}

//Function to insert a new car in the list at the intermediate position.
void insertSpecific()
{
	string numplate;
	int pos;
    struct Node *newnode, *curNode;
    int i;
	cout<<"Enter the number plate : ";
	cin>>numplate;
	cout<<"Enter the position : ";
	cin>>pos;
    if(head == NULL)
    {
        cout<<"Parking lot is empty";
    }
    else
    {
        newnode = new Node;
        newnode->data = numplate;
        curNode = head;
        for(i=0; i<=pos-3; i++) { curNode = curNode->next;
        }
        newnode->next = curNode->next;
        curNode->next = newnode;
    }
}
//Function to delete data of a specific car when it leaves the parking lot.
void deleteSpecific(){             
		int pos;
        struct Node *p,*q;
        int del,k=0;
        cout<<"Enter the position of specific car which leaves the Parking lot : ";
		cin>>pos;
        del=pos-1;
        p=head;
        while(k!=del){
            q=p;
            p=p->next;
            k++;
        }
        q->next=p->next;
        free(p);//deleting specific node
}

//Function to Check if the parking lot is empty
void isEmpty(){
	Node*temp=head;
	if(head==NULL)
	{
		cout<<"\nParking lot is Empty...Right Now!!";
		
	}
	else{
		cout<<"\nParking lot is Not Empty...Right Now!!";
	}
	
}

//Function to check that a particular car is still parked in parking lot or not.
void SearchElement() {
      Node* temp = head;
      string searchValue;
      int found = 0;
      int i = 0;
	cout<<"Enter the number plate of particular car to check it is in Parking Lot or not  : ";
	cin>>searchValue;
      if(temp != NULL) {
        while(true) {
          i++;
          if(temp->data == searchValue) {
            found++;
            break;
          }
          temp = temp->next;
          if(temp == head) {break;}     
        }
        if (found == 1) {
          cout<<"This Car "<<searchValue<<" is found in Parking Lot at Position = "<<i<<".\n";
        } else {
          cout<<searchValue<<" is not found in the Parking Lot.\n";
        }
      } else {
        cout<<"The Parking Lot is empty.\n";
      }
    }
    
//Function to keep a count of the number of cars parked in the parking lot at any time.
int countnode(Node *ptr){
	int count=0;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}

//Function to insert a new car in the list at the end of the parking lot.
void insertAtEnd()
{
	Node *prev;
	string newnumberplate;
	Node* nNew=new Node;
	cout<<"Enter the number plate of new car which you want to insert at the End of the parking lot : ";
	cin>>newnumberplate;
	nNew->data=newnumberplate;
	nNew->next=NULL;
	if(head==NULL)
	{
		cout<<"\nParking lot is Empty"<<endl;
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

//Function to delete the first car from the list.
void delAtbig()
{
	Node* temp;
	if(head==NULL)
	{
		cout<<"The Parking lot is Empty"<<endl;
		
	}
	else{
			temp=head;
			head=temp->next;
			free(temp);	
	}
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
