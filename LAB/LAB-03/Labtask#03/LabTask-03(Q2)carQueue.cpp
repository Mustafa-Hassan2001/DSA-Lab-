#include<iostream>
#include <stdio.h>      
#include <time.h>   
using namespace std;

//LAB-TASK#03 (Question # 02):: 

//Start of class carQueue
class carQueue{
	//Class datamembers 
	public:
	string cars[10];  						//queue size of 10
	int front = -1, rear = -1, n=10;		//frontindex & rearindex is inclized by -1 and n is the size of queue
	string Stack[10];  						//stack size of 10
	int top = -1;
	int size = 10;
	
//Funtion to enter new vlaue in queue 	
void CarsEnterincity(string val) {
   	if ((front == 0 && rear == n-1) || (front == rear+1)) {   //Condition to check queue is full or not
      		cout<<"Queue Overflow \n";
      	return;
   		}
   		if (front == -1) {		// if front index is -1 so it means that queue is empty so before user entry its number frontindex & rearindex will become 0
      	front = 0;
      	rear = 0;
   		} 
	else 						// if queue is not full 
	{
      	if (rear == n - 1)		//if rearindex is full so this condition is true & rearindex will become zero to make our queue circular
      	rear = 0;
      	else
      	rear = rear + 1;		//this will increment of one in rearindex
   		}
   cars[rear] = val ;			//assigend the value of user to rearindex   
	}

//Funtion to delete fisrt vlaue of queue
 void CarsExitfromcity() {
 	time_t t;       	  // t passed as argument in function time()
   struct tm * tt;  	  // decalring variable for localtime()
   time (&t);      		  //passing argument to time()
   tt = localtime(&t);

   if (front == -1) {		//Condition to check queue is full or not
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"The car departed from "<<cars[front]<<"at "<< asctime(tt)<<endl;  // show the name from which car is depated form cars queue

   if (front == rear) {		// if frontindex & rearindex is same it means queue have only one value & all other indexes are empty
      front = -1;        	//so it will assigemed -1 to both indexes
      rear = -1;
   } 
   else 			        	// if frontindex & rearindex is not same
   {
      if (front == n - 1)		//if frontindex is equal to size of queue so it the deleting value is last value 
      front = 0;			   //if this is true so this will assigened 0 to frontindex
      else
      front = front + 1;
   }
}

//Funtion to display all data of cars queue
void displayrecord() {
   int f = front, r = rear;		//initialized frontindex to f & rearindex to r  
   if (front == -1) {		   //Checking if the value of fronntindex is -1 its means Queue is empty
      cout<<"Record is empty"<<endl;
      return;
   }
   cout<<"Car enter's in these city's:\n"<<endl;		//This line will displa all the enteired city's name
   if (f <= r) {			//if fronntindex is greater 0r equal to rearindex it will display the elements of queue
      while (f <= r){
         cout<<cars[f]<<" "<<endl;
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<cars[f]<<" "<<endl;
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<cars[f]<<" "<<endl;
         f++;
      }
   }
   cout<<endl;
}

//Funtion to push vlaue in stack
void push(string city){
		if(top==size-1){
			cout<<"Stack Overflow\n\n";
		}
		else
		{
		top++;
		Stack[top] = city;
		}
	}

//Funtion to Display the top vlaue entired value of stack
void Displayentry(){
	time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);
	for(int i=0; i<top+1; i++){
	cout<<"The car enters in "<<Stack[i]<<"at "<< asctime(tt)<<endl;
	}
}	 

};
//End of class carQueue


int main() {
	carQueue c1;		//class object 
    int ch; 
	string city;
	//Menu of program  
   cout<<"Select From the following menu "<<endl;
   cout<<"-------------------------------"<<endl;		
   cout<<"1-> Car Enter "<<endl;
   cout<<"2-> Car Exit "<<endl;
   cout<<"3-> Display record"<<endl;
   cout<<"4-> Push"<<endl;
   cout<<"5-> Displayentry"<<endl;
   cout<<"6-> Exit"<<endl;
   cout<<"-------------------------------"<<endl<<endl;
   do {
      cout<<"\nEnter choice : ";
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Enter the name of city in which car enter: "<<endl;
         cin>>city;
         c1.CarsEnterincity(city);		//calling CarsEnterincity function of queue
         break;

         case 2:
         c1.CarsExitfromcity();			//calling CarsExitfromcity function of queue
         break;

         case 3:
         c1.displayrecord();			//calling displayrecord function of queue
         break;

		 case 4:
		 cout<<"Enter the name of city in which car enter: "<<endl;
         cin>>city;	
		 c1.push(city);		//calling push function of stack 
         break;
		 	
         case 5:
         c1.Displayentry();		//calling Displayentry function of stack
         break;
         
         case 6:
         cout<<"Exit\n";
         break;
		 default: cout<<"Incorrect!\n";
      }
   } while(ch != 6);
   return 0;
}
