#include<iostream>
using namespace std;
int binarySearch(int array[], int x, int low, int high) { //SADA 
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int recursiveLinearSearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return recursiveLinearSearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

	
	
int main() {  
    cout<<"Enter The Size Of Array:   ";
    int size;
    cin>>size;
    int array[size], key,i;
    for(int j=0;j<size;j++){
    cout<<"Enter "<<j<<" Element : ";
    cin>>array[j];
    }
    for(int a=0;a<size;a++){
       cout<<"array[ "<<a<<" ]  =  ";
       cout<<array[a]<<endl;
    }
    cout<<"Enter Key To Search  in Array";
    cin>>key;
    
    cout<<"\n\n---------WITH RECRSIVE FUNCTION---------\n\n";
    int result1;
    result1=recursiveLinearSearch(array,key,0,size-1);
    if(result1==1){
    cout<<"Key Found in Array  ";
    }
    else{
    cout<<"Key NOT Found in Array  ";
    }
    
	cout<<"\n\n---------WITH-OUT RECRSIVE FUNCTION---------\n\n";
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, key, 0, n - 1);
  if (result == -1)
    cout<<"Not found";
  else
    cout<<"Element is found at index" << result;
    
       return 0;
    }
