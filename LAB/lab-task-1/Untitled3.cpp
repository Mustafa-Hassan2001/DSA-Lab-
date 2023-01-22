#include <iostream>
using namespace std;

int main(int argc, char** argv) {

	int n,i;
	int arr[n];
	int num;
	cout<<"Enter the size of array :" ;
	cin>>n;
	cout<<"Enter the element of array :";
	for(i=0;i<=n;i++){
		cin>>arr[i];
	}
	cout<<"Before Inseration :";
	for (i=0;i<=n;i++){
		cout<<arr[i]<<endl;
	}
	cout<<"Enter the number you want to insert :";
	cin>>num;
	arr[0]==num;
	for( i=0;i<=n;i++){
		arr[n+1]=arr[n];
	}
	cout<<"After Inseration :";
	for ( i=0;i<=n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
