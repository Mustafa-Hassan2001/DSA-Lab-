#include <iostream>
using namespace std;
int fib(int num) {
   if((num==1)||(num==0)) {
      return 1;
   }
   else {
      return(fib(num-1)+fib(num-2));
   }
}
int main() {
   int num, i=0;
   cout << "Enter the number : ";
   cin >> num;
   cout << "Fibonnaci Series : 0 ";
   while(i < num) {
      cout << " " << fib(i);
      i++;
   }
 return 0;
}
