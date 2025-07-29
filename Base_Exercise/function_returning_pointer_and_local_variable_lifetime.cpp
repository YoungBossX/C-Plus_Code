#include "iostream"

using namespace std;

int* add1(int a, int b) {
    int sum = a + b;
    return &sum; 
}

int* add2(int a, int b) {
    int* sum = new int(a + b);

    return sum; 
}

int main() {
    // int* result1 = add1(1, 2);
    // cout << *result1 << endl;

    int* result2 = add2(1, 2);
    cout << *result2 << endl;

    delete result2;
    return 0;
}  