#include <iostream>
using namespace std;
///* runce this program using the console pauser or add your own getch, system("pause") or input loop */
int size=5, flag, popval, last;
class Palindrome{
	public:
		char stack[5];
		int top;
		Palindrome(){
			top=-1;
		}
		void push ( char name ){
			if(top==size-1){
				cout<<"Stack Overflow";
			}
			else{
				top++;
				stack[top]=name;
			}
		}
		void pop(){
			if(top=-1){
				cout<<"Stack is Empty";
			}
			else{
				popval = top;
				top--;
			}
		}
		void display(){
			for(int i=0;i<=top;i++){
				cout<<stack[i]<<endl;
			}
		}
		void palindrome(){
			if(top!=-1){
				last = top;
			}
			for(int i=0;i<last+1;i++){
			if(stack[i]==stack[last-1]){
					flag=1;
					last--;
				}
				else{
					flag=0;
				}
			}
			if(flag==1){
				cout<<"It is Palindrom";
			}
			else{
				cout<<"It is not Palindrom";
			}
		}

};


int main(int argc, char** argv) {
	Palindrome p1;
	char read;
	char value;
	cout<<"Enter Character : ";
	cin>>read;
	p1.push(read);
	A:
	cout<<"Enter Again [Y/N] : " ;
	cin>>value;
	if(value=='Y'||value=='y'){
		cout<<"Enter Character : ";
		cin>>read;
		p1.push(read);
		goto A;
	}
	else{
		p1.display();
	}
	p1.palindrome();
	
	return 0;
}
