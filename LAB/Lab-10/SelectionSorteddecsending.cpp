#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int temp = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] > array[temp])
        temp = j;
    }
    swap(&array[temp], &array[i]);
  }
}

int main() {
  int data[] = {0, 12, 1, 5, 2};
  int size = 5;
  selectionSort(data, size);
  cout << "Selection Sorted array in decsending Order: ";
  printArray(data, size);
}
