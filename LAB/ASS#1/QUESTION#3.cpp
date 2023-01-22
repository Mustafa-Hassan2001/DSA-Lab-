#include <iostream>
using namespace std;

class InfixtoPostfix{
	public:
		int top;
		char stack[20], a[20];
		void enterinfix();
		void push(char x);
		char pop();
		int precedence(char x);
		void convert();
};

void InfixtoPostfix::enterinfix(){
	cout<<"Enter Infix Expression : ";
	cin>>a;
}

void InfixtoPostfix::push(char x){
	stack[++top] = x;
}

char InfixtoPostfix::pop(){
	return stack[top--]; 
}

int InfixtoPostfix::precedence(char c){
	if(c == '+' || c == '-')
	return 1;
	
	else if(c == '*' || c == '/')
	return 2;
	
	else if(c == '^')
	return 3;
	
	else
	return -1;
}

void InfixtoPostfix::convert(){
	char c,x;
	int i;
	
	cout<<"The Postix Expression of your Infix is : ";
	
	for(i=0; a[i]!='\0'; i++){
		c=a[i];
		if(precedence(c)>0){
			while(top!=-1 && precedence(stack[top])>=precedence(c)){
				cout<<pop();
			}
			push(c);
		}
		else if(c == ')'){
			x = pop();
			while(x!='('){
				cout<<x;
				x=pop();
			}
		}
		else if(c == '(')
		push(c);
		else
		cout<<c;
	}
	
	for(i=0;i<=top+1;i++){
	cout<<pop();
	}
}

int main(){
	InfixtoPostfix i;
	i.enterinfix();
	i.convert();
}
