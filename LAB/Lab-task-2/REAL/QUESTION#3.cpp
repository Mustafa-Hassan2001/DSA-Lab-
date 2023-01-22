#include<iostream>
#include<string>
using namespace std;
int size = 5,flag,popValue;

class stack{
	int truckId[5];
	int top;
	public:
	stack(){
		top = -1;
	}	
	void push(char num){
			if(top==size-1){
				cout<<"Stack Overflow\n\n";
			}
			else{
				top++;
				truckId[top] = num;
			}
	} // end of func
	void pop(){
		if(top == -1){
			cout<<"Stack is Empty";
		}
		else{
			popValue = top;
			top--;
		}
	}
	void display(){
		for(int i=0; i<top+1; i++){
			cout<<truckId[i]<<endl;
		}
	}
	void search(int num){
		for(int i=0; i<top+1; i++){
			if(num==truckId[i]){
				cout<<" Truck Found TRUCK ID: "<<truckId[i];
				flag = 0;
				break;

			}
			
			if(flag!=0){
				cout<<"Truck Not Found";
			}
		}
	}
};
int main(){
	stack obj;
	int TruckId,num;
	char value;
	cout<<"Enter Truck ID: ";
	cin>>TruckId;
	obj.push(TruckId);
	A:
	cout<<"Do you want push another element |Y/N|: ";
	cin>>value;
	if(value == 'Y' || value == 'y'){
		cout<<"Enter Truck ID: ";
		cin>>TruckId;
		obj.push(TruckId);
		goto A;
	}
	else{
	cout<<"Total Entered Trucks In Garage(ID Wise): ";
	obj.display();
	}
	cout<<"Enter Truck ID To Search: ";
	cin>>num;
	obj.search(num);
	
	B:
	cout<<"\nDo you want pop element |Y/N|: ";
	cin>>value;
	if(value == 'Y' || value == 'y'){
		obj.pop();
		goto B;
	}
	else{
	cout<<"Total Remaining Trucks In Garage(ID Wise): ";
	obj.display();
	}
	
}
