#include "iostream"

using namespace std;

/*
 * 引用传参:
 * void func(int &a, int &b);
 */

void switch_num1(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void switch_num2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void switch_num3(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a=10, b = 20;
    switch_num1(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    switch_num2(&a, &b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    switch_num3(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    
    return 0;
}   