#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//int size = 10;

class queue {
		public:	
		int frontIndex=-1;
		int rearIndex=-1;
		int queue[10]; 
		void init(){
			for( int i=0; i<10;i++){
				queue[i] = 0;
			}
		}
		void enqueue(int number){
			if(rearIndex >= 9){
				cout<<"Queue is Empty"<<endl;
			}
		if(frontIndex == -1 && rearIndex == -1){
			frontIndex ++;
			rearIndex  ++;
			queue[rearIndex] = number;
		}
		if( rearIndex <= 9){
			rearIndex = rearIndex + 1;
			queue[rearIndex] = number;
		} 
		else if(rearIndex > 11){
				cout<<"Queue is Full"<<endl;
		}
		
		}
		 void dqueue(){
			if(frontIndex ==-1 && rearIndex ==-1 || frontIndex == 10){
				cout<<"Queue is Empty"<<endl;
			}	
			if(frontIndex !=-1 && frontIndex > rearIndex){
				cout<<"Queue is empty";
			}
			if(frontIndex != -1|| frontIndex != 9){
				cout<<queue[frontIndex]<<endl;
				queue[frontIndex] = 0;
				frontIndex = frontIndex + 1;
			}
		} 
		void display(){
			for( int i=0; i<10;i++){
				cout<<queue[i]<<" ";
			}
		}
};

int main(int argc, char** argv) {
	
	queue user;
	user.init();
	cout<<endl;
	cout<<"==========================="<<endl;
	cout<<"Before User Data :"<<endl<<endl;
	user.display();
	user.enqueue(10);
	user.enqueue(20);
	user.enqueue(30);
	user.enqueue(40);
	user.enqueue(50);
	user.enqueue(60);
	user.enqueue(70);
	user.enqueue(80);
	user.enqueue(90);
	user.enqueue(100);
	cout<<"\n==========================="<<endl;
	cout<<"\nAfter User Data :"<<endl<<endl;
	user.display();
	cout<<"\n==========================="<<endl;
	
//	user.display();
	user.dqueue();
	user.dqueue();
	user.dqueue();
	user.dqueue();
	cout<<"\nAfter deleting User Data :"<<endl<<endl;
	cout<<"\n==========================="<<endl;
	user.display();
	
//	int queue[size];
//	int userNumber;
//	if (frontIndex==-1 && rearIndex==-1){
//		cout<<"Queue is Empty";
//	}
//	
//	while(userNumber == 0){
//	cout<<"Enter Number or type-1 for exit";
//	cin>>userNumber;
//	
//	if (frontIndex==-1 && rearIndex==-1){
//		frontIndex = 0;
//		rearIndex = 0;
//		queue[rearIndex] = userNumber;
//	}
//	if(rearIndex < size-1){
//		rearIndex++;
//		queue[rearIndex] = userNumber;
//	}
//	if(frontIndex != -1 || frontIndex != size){
//		cout<<queue[frontIndex];
//		queue[frontIndex] = 0;
//		frontindex = frontIndex + 1;
//	}
//	}	
	return 0;
}
