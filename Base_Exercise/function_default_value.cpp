#include "iostream"

using namespace std;

/*
 * 编写函数的时候，可以给参数提供默认值。
 * 一旦为某个参数提供默认值，其右侧全部参数，必须提供默认值。
 */

void say_hello(const string& name = "XCC") {
    cout << "Hello, " << name << "!" << endl;
}

void add(int x, int y=20, int z=30) {
    int sum = x + y + z;
    cout << "Sum: " << sum << endl;
}

void add2(int x=0) {
    cout << x << endl; 
}

int main() {
    say_hello();
    say_hello("xcc");
    add(20);
    add2();

    return 0;
}  