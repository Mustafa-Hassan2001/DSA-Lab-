#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int arr1[2][2], arr2[2][2], result[2][2];
	int i,j;
	cout<<"Enter the elements of array-1: "<<endl;
	for(i=0;i<=4;i++){
		for(j=0;j<=4;j++){
			cin>>arr1[4][4];
		}
	}
	cout<<endl;
	cout<<"Enter the elements of array-2: "<<endl;
	for(i=0;i<=4;i++){
		for(j=0;j<=4;j++){
			cin>>arr2[4][4];
		}
		
	}	
	for(i=0;i<=4;i++){
		for(j=0;j<=4;j++){
			result[i][j] =  arr1[i][j] + arr2[i][j];
		}
	}	
	cout<<"Result :"<<endl<<endl ;
	for(i=0;i<=4;i++){
	    for(j=0;j<=4;j++){
		cout<<result[i][j]<<endl;
		}
	}
	
	return 0;
}
