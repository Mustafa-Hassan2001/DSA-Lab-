#include<iostream>
using namespace std;
int linearsearch(){
	int arr[10], i, num, index;
    cout<<"Enter 4 Numbers: ";
    for(i=0; i<4; i++)
        cin>>arr[i];
    cout<<"\nEnter a Number to Search: ";
    cin>>num;
    for(i=0; i<10; i++)
    {
        if(arr[i]==num)
        {
            index = i;
            break;
        }
    }
    cout<<"\nFound at Index No."<<index;
    cout<<endl;
}

int recursiveLinearSearch(int array[],int key,int size) {		//BOYI WALA
	size=size-1;
	if(size <0) {
		return -1;
	} else if(array[size]==key) {
		return 1;
	} else {
		return recursiveLinearSearch(array,key,size);
	}
}

int main(){
	cout<<"\n\n---------WITH-OUT RECRSIVE FUNCTION---------\n\n";
    linearsearch();
    
    cout<<"\n\n---------WITH RECRSIVE FUNCTION---------\n\n";
    cout<<"Enter The Size Of Array:   ";
	int size;
	cin>>size;
	int array[size], key,i;
	for (int j=0;j<size;j++) {
		cout<<"Enter "<<j<<" Element : ";
		cin>>array[j];
	}
	for (int a=0;a<size;a++) {
		cout<<"array[ "<<a<<" ]  =  ";
		cout<<array[a]<<endl;
	}
	cout<<"Enter Key To Search  in Array";
	cin>>key;
	int result;
	result=recursiveLinearSearch(array,key,size--);
	if(result==1) {
		cout<<"Key Found in Array  ";
	} else {
		cout<<"Key NOT Found in Array  ";
	}
    return 0;
}
