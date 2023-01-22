#include <iostream>
using namespace std;
const int MAX=20;

class QUEUE{
	public:
	int queue[8];
	int front = -1, rear = -1, n=8;
	int stack[MAX];
    int top=-1;
    int sum[], res[];
    

 void Insert(int val) {
   	if ((front == 0 && rear == n-1) || (front == rear+1)) {
      		cout<<"Queue Overflow \n";
      	return;
   		}
   		if (front == -1) {
      	front = 0;
      	rear = 0;
   		} 
	else {
      	if (rear == n - 1)
      	rear = 0;
      	else
      	rear = rear + 1;
   		}
   queue[rear] = val ;
	}

 void Delete() {
 	int n;
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<queue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}

int sumqueue(int queue[]){	
	QUEUE q;		
//   	for(int i=0;i<=n;i++){			// suming the value of queue
	   	for(int j=0;j<=n;j++){
   		sum[j] = q.queue[front] + q.queue[front+1] ;
	   }
//	   }   

// pushing the  value of sum queue in stack 
if (top== MAX- 1)
{
	cout<<"\n stack is full!";
}
else
{
	top++ ;
	stack[top] =sum[20];
}
}

void display()
{
	int temp = top;
	while (temp!=- 1)
	{
		cout << "\n" << stack[temp]<<endl;
		temp=temp-1;
		//cout<<"temp is "<<temp;
		
	}	
}

};

int main() {
	QUEUE Q1;
    int ch, val;
    int queue[]={7,8,9,112,55,77,76,12};
   cout<<"1)Insert"<<endl;
   cout<<"2)Delete"<<endl;
   cout<<"3)Sum Queue"<<endl;
   cout<<"4)Display stack"<<endl;
   cout<<"5)Exit"<<endl;
   do {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         Q1.Insert(val);
         break;

         case 2:
         Q1.Delete();
         break;

         case 3:
         Q1.sumqueue(queue);
         break;
		 
		 case 4:
         Q1.display();
         break;
		 	
         case 5:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 5);
   return 0;
}
