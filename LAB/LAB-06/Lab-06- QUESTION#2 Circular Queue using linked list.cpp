#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};
Node *front  = NULL, *rear = NULL;

void enqueue(int data){
  	Node* newnode;
	newnode = (Node*)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	if((rear==NULL)&&(front==NULL))
	{
		front = rear = newnode;
		rear->next = front; //Condition to make circular queue
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
		newnode->next = front;
	}
} 

void dequeue(){
	Node* temp;
	temp = front;
	if((front==NULL)&&(rear==NULL))
		cout<<"\nQueue is Empty";
	else if(front == rear){
		front = rear = NULL;
		free(temp);
	}
	else{
		front = front->next;
		rear->next = front;
		free(temp);
	    cout<<"\nDequeue element is : "<<temp->data<<endl;
	}
}

void display(){ // Print the elements of Queue
	Node* temp;
	temp = front;
	if((front==NULL)&&(rear==NULL))
		cout<<"\nQueue is Empty";
	else{
		do{
			cout<<" "<<temp->data;
			temp = temp->next;
		}while(temp != front);
	}
}

int main(){

	int opt,n,i,data;
	while(opt != 4)   
    {
		cout<<"\n\n 1-> Insert the Data in Queue\n 2-> show the Data in Queue \n 3-> Delete the data from the Queue\n 4-> Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>opt;
		switch(opt){
			case 1:
				cout<<"\nEnter your data : ";
				cin>>data;
				enqueue(data);
				break;
			case 2:
				display();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				cout<<"\nIncorrect Choice";
			
		}
	}
return 0;
}
