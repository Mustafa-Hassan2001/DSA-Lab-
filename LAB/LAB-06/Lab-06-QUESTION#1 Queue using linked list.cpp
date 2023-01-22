#include<iostream>
#include<stdlib.h>

using namespace std;
struct Node{
	int data;
	Node* next;
};

Node* head=NULL;
Node *front=NULL,*rear=NULL;

void enqueue(){  
    Node *ptr;  
    int item;   
      
    ptr = (struct Node *) malloc (sizeof(struct Node));  
    
    if(ptr == NULL)  
    {  
        cout<<"\nOVERFLOW\n";  
        return;  
    }  
    else  
    {   
        cout<<"\nEnter value : ";  
        cin>>item;  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void dequeue ()  
{  
    Node *ptr;  
    if(front == NULL)  
    {  
        cout<<"\nUNDERFLOW\n";  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
        cout<<"\nDequeue element is : "<<ptr->data<<endl;
    }  
}  
void display()  
{  
    Node *ptr;  
    ptr = front;
	cout<<endl;      
    if(front == NULL)  
    {  
        cout<<"\nEmpty queue\n";  
    }  
    else  
    {    
        while(ptr != NULL)   
        {  
            cout<<" "<<ptr -> data;  
            ptr = ptr -> next;  
        }  
    }
    cout<<endl;
}

int main(){

    int choice;   
    while(choice != 4)   
    {      
        cout<<"\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n";  
        cout<<"Enter your choice : ";  
        cin>>choice;  
        
        switch(choice)  
        {  
            case 1:  
            enqueue();  
            break;  
            case 2:  
            dequeue();  
            break;  
            case 3:  
            display();  
            break;  
            case 4:  
            exit(0);  
            break;  
            default:   
            cout<<"Enter valid choice";  
        }  
    }  
	return 0;
} 
