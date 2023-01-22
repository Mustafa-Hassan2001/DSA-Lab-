#include <iostream>
using namespace std;
//LAB-TASK#03 (Question # 01)::

//Start of class QUEUE
class QUEUE{
	public:
	int queue[5];  //queue
	int front = -1, rear = -1, n=5; //frontindex & rearindex is inclized by -1 and n is the size of queue

//Funtion to enter new vlaue in queue 
void EQueue(int val) {
   	if ((front == 0 && rear == n-1) || (front == rear+1)) { //Condition to check queue is full or not
      		cout<<"Queue Overflow \n";
      	return;
   		}
   		if (front == -1) {  // if front index is -1 so it means that queue is empty so before user entry its number frontindex & rearindex will become 0
      	front = 0;
      	rear = 0;
   		} 
	else 					// if queue is not full  
	{
      	if (rear == n - 1) 	//if rearindex is full so this condition is true & rearindex will become zero to make our queue circular 
      	rear = 0;
      	else
      	rear = rear + 1; 	//this will increment of one in rearindex
   		}
   queue[rear] = val ;  	//assigend the value of user to rearindex   
	}
	
//Funtion to delete fisrt vlaue of queue
void DeQueue() {
   if (front == -1) {  		//Condition to check queue is full or not
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<queue[front]<<endl; // show the value which is deleted form queue

   if (front == rear) {  // if frontindex & rearindex is same it means queue have only one value & all other indexes are empty
      front = -1;        //so it will assigemed -1 to both indexes
      rear = -1;
   } 
   else 				// if frontindex & rearindex is not same
   {
      if (front == n - 1)	//if frontindex is equal to size of queue so it the deleting value is last value 
      front = 0;			//if this is true so this will assigened 0 to frontindex
      else
      front = front + 1;
   }
}
//Funtion to display all vlaue of queue
void display() {
   int f = front, r = rear; //initialized frontindex to f & rearindex to r  
   if (front == -1) {		//Checking if the value of fronntindex is -1 its means Queue is empty
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";  //this line dipaly  all the elements of queue
   if (f <= r) {		  //if fronntindex is greater 0r equal to rearindex it will display the elements of queue
      while (f <= r){		
         cout<<queue[f]<<" ";
         f++;
      }
   } 
   else 
   {
      while (f <= n - 1) {
         cout<<queue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<queue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}

//Funtion to display PEEK vlaue of queue
void PEEK(){
	if( front = -1 ){
		cout<<"Queue Underflow"<<endl;
	}
	else {
		cout<<"Peek value of queue is : "<<queue[front]<<endl;
	}
}

};
//End of class QUEUE


int main() {
   QUEUE Q1; 	//class object 
   int ch, val;
   //Menu of program  
   cout<<"Select From the following menu "<<endl;
   cout<<"-------------------------------"<<endl;
   cout<<"1-> EnQueue"<<endl;
   cout<<"2-> DeQueue"<<endl;
   cout<<"3-> Display"<<endl;
   cout<<"4-> PEEK"<<endl;
   cout<<"5-> Exit"<<endl;
   cout<<"-------------------------------"<<endl<<endl;
   do {
      cout<<"\nEnter choice : ";
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Enter a number: "<<endl;
         cin>>val;
         Q1.EQueue(val);	//calling EnQueue function 
         break;

         case 2:
         Q1.DeQueue();		//calling DeQueue function 
         break;

         case 3:
         Q1.PEEK();		//calling PEEK function 
         break;

		 case 4:
         Q1.display();		//calling display function 
         break;
		 	
         case 5:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 5);
   return 0;
}
