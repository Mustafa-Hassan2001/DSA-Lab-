#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size - i; ++i) {
      if (array[j] < array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {2, 4, 10, 1, 9};
  int size = 5;
  bubbleSort(data, size);
  cout << "Sorted Array in Descending Order:\n 10,9,4,2,1";  
  printArray(data, size);
}
