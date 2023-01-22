#include <iostream>
using namespace std;
void print_array(int arr[], int size){
	
for (int i = 0; i < size; i++){
cout << arr[i] << " ";
}
cout << endl;
}
void insertion_sort(int arr[], int size){
for (int step = 1; step < size; step++){
int key = arr[step];
int j = step - 1;
while (key > arr[j] && j >= 0){
arr[j + 1] = arr[j];
--j;
}
arr[j + 1] = key;
}
}

int main(){
int arr[] = {9, 5, 1, 4, 3};
int size = sizeof(arr) / sizeof(arr[0]);
insertion_sort(arr, size);
cout << "Sorted array in descending order:\n";
print_array(arr, size);
}
