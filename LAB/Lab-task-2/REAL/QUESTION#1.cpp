#include<iostream>
#include<string>
using namespace std;
int size = 20,count = 1,counter=0,popValue;
class stack{

int Stack[20];
int top;
public:
stack(){
top = -1;
}
void push(int num){
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
};
int main(){
stack obj;
int num;
char value;
cout<<"Enter Num: ";
cin>>num;
obj.push(num);
A:
cout<<"Do you want push another element |Y/N|: ";
cin>>value;

if(value == 'Y' || value == 'y'){
cout<<"Enter Num: ";
cin>>num;
obj.push(num);
count++;
goto A;
}
else{
obj.display();
cout<<"Total Pushed Elements Are "<<count;
}

B:
cout<<"\nDo you want pop element |Y/N|: ";
cin>>value;

if(value == 'Y' || value == 'y'){
obj.pop();
counter++;
goto B;
}
else{
obj.display();
cout<<"Total Poped Elements Are "<<counter;
}

}
