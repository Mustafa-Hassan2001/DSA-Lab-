#include<iostream>
#include<string>
using namespace std;
int size = 5,flag, popValue,lastCharacter;
class stack{
	
	char Stack[5];
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
				Stack[top] = num;
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
			cout<<Stack[i]<<endl;
		}
	}
	void Palindrome(){
		if(top!=-1){
			lastCharacter = top;
		}
		for(int i=0; i<lastCharacter+1; i++){
			if(Stack[i]==Stack[lastCharacter-1]){
				flag = 1;
				lastCharacter--;
			}
			else{
				flag = 0;
			}
		}
		
		if(flag == 1){
			cout<<"String is Palindrome";
		}
		else
			cout<<"String is Not Palindrome";
	}
};
int main(){
	stack obj;
	char read;
	char value;
	cout<<"Enter Character: ";
	cin>>read;
	obj.push(read);
	A:
	cout<<"Do you want push another element |Y/N|: ";
	cin>>value;
	
	if(value == 'Y' || value == 'y'){
		cout<<"Enter Character: ";
		cin>>read;
		obj.push(read);
		goto A;
	}
	else{
	obj.display();
	}
	
	B:
	cout<<"\nDo you want pop element |Y/N|: ";
	cin>>value;
	
	if(value == 'Y' || value == 'y'){
		obj.pop();
		goto B;
	}
	else{
	obj.display();
	}
	obj.Palindrome();
	
}
