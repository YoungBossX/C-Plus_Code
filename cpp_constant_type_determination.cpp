#include "iostream"

using namespace std;

int main(){
    // 不带有后缀的数字的类型确定，整数的类型最小是int，小数的最小类型是double
    cout << "10的字节数是：" << sizeof(10) << " bytes" << endl;
    cout << "99999999999的字节数是：" << sizeof(99999999999) << " bytes" << endl;
    cout << "3.14的字节数是：" << sizeof(3.14) << " bytes" << endl;

    // 带有后缀的数字的类型确定，U无符号的意思，L表示长整型，F表示单精度浮点数，D表示双精度浮点数
    cout << "10L的字节数是：" << sizeof(10L) << " bytes" << endl; 
    cout << "10U的字节数是：" << sizeof(10U) << " bytes" << endl;
    cout << "3.14F的字节数是：" << sizeof(3.14F) << " bytes" << endl;
    cout << "3.14D的字节数是：" << sizeof(3.14D) << " bytes" << endl;

    return 0;
}   