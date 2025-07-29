#include "iostream"

using namespace std;

int* add1(int a, int b) {
    static int sum = a + b;
    return &sum; 
}

int main() {
    int* result = add1(1, 2);
    cout << *result << endl;

    return 0;
} 