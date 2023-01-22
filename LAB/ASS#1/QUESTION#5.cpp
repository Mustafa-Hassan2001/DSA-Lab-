#include <iostream>
using namespace std;

string friendQueue[5];
int front = -1, rear = -1, n=5;

void equeue(string val) {
   if ((front == 0 && rear == n-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   friendQueue[rear] = val ;
}

void dequeue() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"\nDeleted from friend queue is : "<<friendQueue[front]<<endl;

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
void display() {
   int f = front, r = rear;
   if (front == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"\nName in you Friend Queue are :\n";
   if (f <= r) {
      while (f <= r){
         cout<<friendQueue[f]<<" ";
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<friendQueue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<friendQueue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}
int main() {

   int opt;
   string name;
   cout<<"1-> Enter Name \n";
   cout<<"2-> Delete Name\n";
   cout<<"3-> Display All Name\n";
   cout<<"4-> Exit\n";
   do {
      cout<<"\nEnter choice : "<<endl;
      cin>>opt;
      switch(opt) {
         case 1:
         cout<<"\nEnter your friend name: "<<endl;
         cin>>name;
         equeue(name);
         break;

         case 2:
         dequeue();
         break;

         case 3:
         display();
         break;

         case 4:
         cout<<"\Exit\n";
         break;
         default: cout<<"\nIncorrect!\n";
      }
   } while(opt != 4);
   return 0;
}
