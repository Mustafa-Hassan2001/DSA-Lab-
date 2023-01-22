#include<iostream>
#include<string>
using namespace std;
const int MAX=20;

//Using OOP method of template for stack	
template <typename T>
class Stack{
	private:
		char stack[MAX];
		int top;
	public:
        //constructor
		Stack(){
			top=-1;
		}
		//to push the elements
		T Push(T ele){
			if(top==MAX-1){
				cout<<"Stack is full!";

			}
			else{
				top++;
				stack[top]=ele;

			}
		}
		//to pop the elements
		T Pop(){
			if(top<=-1){
				cout<<"Stack is Empty! ";

			} 
			else{
				T temp = stack[top];
				top--;
				return temp;
			}
			return NULL;
		}
		//for checking the top most element
		T Peek(){
			return stack[top];
		}
		//display the final result
		void display(){
			int temp=top;
			
			while(temp!=-1){
				cout<<stack[temp]<<endl;
				temp--;
			}
		}
        //function to check whether stack is empty or not
		bool Empty(){
			if(top == -1){
				return true;
			}
			return false;
		}


};

//For checking if there are operators in th expression
bool Operators(char op){
	
	if(op=='+'||op=='-'||op=='*'||op=='/'){
		return true;
	}
	else{
		return false;
	}
}

int Check_precedence(char op){ 

    if(op == '*' || op == '/') 
    return 2; 
    else if(op == '+' || op == '-') 
    return 1; 
    else
    return -1; 
} 

//function to convert infix to postfix
string Infix_to_postfix(string infix){
	int temp;
	
	string postfix;
	Stack <char> st;
	for(int i=0;i<infix.size();i++){
		if(infix[i]>= '0' && infix[i]<= '9'){
			postfix+=infix[i];
		}
		else if(infix[i] == '('){
			st.Push(infix[i]);
		}
		else if(infix[i] == ')'){
			while((st.Peek()!='(') && (!st.Empty())){
			
				int temp=st.Peek();
				postfix+=temp;
				st.Pop();
			}
			if(st.Peek()=='('){
				st.Pop();
			}
		}
		    else if(Operators(infix[i])){
			if(st.Empty()){
				st.Push(infix[i]);
			}
			else{
				if(Check_precedence(infix[i])>Check_precedence(st.Peek())){
					st.Push(infix[i]);
				}	
				else if((Check_precedence(infix[i])==Check_precedence(st.Peek()))&&(infix[i]=='/')){
					st.Push(infix[i]);
				}
				else{
					while((!st.Empty())&&(Check_precedence(infix[i])<=Check_precedence(st.Peek())))
					{
						postfix+=st.Peek();
						st.Pop();
					}
					st.Push(infix[i]);
				}
			}
		}
	}
	while(!st.Empty()){
		postfix+=st.Peek();
		st.Pop();
	}
	
	return postfix;
}

//Calculate the total value after converting the infix epxression to postfix
int Calculate(string ele){
	int a=ele.length();
	Stack <int> temp;
	int a1,a2;
	
	for(int i=0; i<a; i++){
		
		if(Operators(ele[i])){
			a1 = temp.Pop();
			cout << endl;
			cout << a1 << endl;
			a2 = temp.Pop();
			cout << a2 << endl;
			
			if(ele[i] == '/'){
				temp.Push(a2/a1);
				
			} 
			else if(ele[i] == '*'){
				temp.Push(a2*a1);
			} 
			else if(ele[i] == '+'){
				temp.Push(a2+a1);
			} 
			else if(ele[i] == '-'){
				temp.Push(a2-a1);
			}
		
		}
		else{
			temp.Push(ele[i]-'0');
		}
	}
	return temp.Pop();

}


int main(){  

  	string infixexp, postfixexp;
  	
  	//Enter the infix
  	cout<<"Enter infix expression :"<<endl;
  	cin>>infixexp;
  	
  	//Converting the infix to postfix expression
  	postfixexp = Infix_to_postfix(infixexp);
  	
  	cout<<endl<<"Postfix expression is : "<<postfixexp;
  	cout<<endl<<"Answer of solution is: "<<Calculate(postfixexp);
    
    return 0;
}

