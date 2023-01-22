#include <iostream>
using namespace std;
//this program is for madam & all 5 charater words

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class stack{
	public:
		int top,size; 
		char stk[];
	public:
	stack(){
		top=-1;
	}
	void push(char);
	void palidrom();
};	
	void stack::push(char element){
		if(top==size-1){
			cout<<"Stack Overflow"<<endl;
		}
		else{
			top=top++;
			stk[top]=element;
		}
	}
	
	void stack::palidrom(){
		if(top!=-1){
		 char lastchar=top;
		}
		int flag=0;
		for(int i=0;i<top+1;i++){
			if(stk[i]==stk[top-1]){
				cout<<stk[i];
				flag=1;
				top--;
			}
			else{
				flag=0;
			}
		}
		if(flag==0){
//			for(int i=0;i<top-1;i++){
//			cout<<stk[i];	
//			}
//			cout<<endl;
			cout<<"It is Palindrom";
		} 
		else{
//			for(int i=0;i<top-1;i++){
//			cout<<stk[i];	
//			}
//			cout<<endl;
			cout<<"It is not Palindrom";
		}
	}

int main(int argc, char** argv) {
	stack s1;
	char read;
	for(int i=0;i<=4;i++){
	cout<<"Enter number :: ";
	cin>>read;
	s1.push(read);
	}
	s1.palidrom();
	

	return 0;
}
