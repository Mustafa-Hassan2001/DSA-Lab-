#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class stack{
	public:
		int top,size; 
		int stk[4];
	public:
	stack(){
		top=-1;
	}
	void push(int);
	int pop();
	void display();
};	
	void stack::push(int element){
		if(top==size-1){
			cout<<"Stack Overflow"<<endl;
		}
		else{
		
			stk[top]=element;
			top=top++;
		}
	}
	
	int stack::pop(){
	if(top==-1){
		cout<<"Stack Overflow"<<endl;
	}		
	else{
		int item = stk[top];
		top=top-1;
		cout<<"Deleted Element"<<endl;
		return item;
	}
	}
	
	void stack::display(){
		for(int i=0;i<top-1;i++){
			cout<<stk[i];
		}
	}




int main(int argc, char** argv) {
	stack s1;
	int num;
	for(int i=0;i<=3;i++){
	cout<<"Enter number :: ";
	cin>>num;
	s1.push(num);
	}
	s1.display();
	s1.pop();
	s1.pop();
	s1.display();
	return 0;
}
