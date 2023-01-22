#include <iostream>
using namespace std;

int main() {
    int term1 = 0, term2 = 1, next = 0, num;
    cout << "Enter a positive number: ";
    cin >> num;
    cout << "Fibonacci Series: " << term1 << " " << term2 << " ";

    next = term1 + term2;

    while(next <= num) {
        cout << next << " ";
        term1 = term2;
        term2 = next;
        next = term1 +term2;
    }
    return 0;
}
