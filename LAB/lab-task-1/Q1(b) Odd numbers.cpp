#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int arr[10], res[10], size;
	cout<<"Enter the size of array :"<<endl;
	cin>>size;
	cout<<"Enter the elements :"<<endl;
	for(int i=0;i<=size;i++){
		cin>>arr[i];
	}
	cout<<"Odd Numbers are :"<<endl;
	for(int i=0;i<=size;i++){
		if(arr[i]%2!=0){
			cout<<arr[i];
		}
	}
	
	return 0;
}
