#include "iostream"

using namespace std;

int main() {
    // int num1 = 10;

    // if (1) {
    //     int num2 = 200;
    //     num1 +=1;
    // } 

    // cout << "num1: " << num1 << endl;

    // cout << "num2: " << num2 << endl; // num2不可以访问，因为它在if语句的作用域内

    // 虽然i在外部作用域中定义，但在for循环中重新定义了i，因此在for循环外部无法访问i，内部可以访问i
    for (int i = 0; i < 5; i++) {
        cout << "i: " << i << endl;
    }
    // cout << "i: " << i << endl;

    return 0;
}