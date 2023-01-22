#include <iostream>
using namespace std;

int isBalBraces(string str[], int size){ 
	int flag1 = 0,flag2 = 0;
	for(int i=0;i<size;i++){
		if(str[i] == "("){
			flag1 ++;
		}
		else if( str[i]==")"){
			flag2 ++;
		}
	}
	if(flag1 = flag2){
			cout<<"\nBalanced"<<endl;
	}
	else{
			cout<<"\nNot Balanced"<<endl;
	}
}

int main(){
	int size;
	string arr[20];
	cout<<"Enter the size : ";
	cin>>size;
	for(int i=0;i<size;i++){
	cout<<"Enter the Character : ";
	cin>>arr[i];	
	}
	isBalBraces(arr , size);
	return 0;
}
