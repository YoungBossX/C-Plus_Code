#include "iostream"

using namespace std;

#define PI 3.14159 

const int count = 10;

int main() {
    // short、long、int、long long
    short age = 18;
    cout << "年龄是：" << age << endl;

    int num1 = 10;
    long num2 = 20;
    long long num3 = 30;
    cout << "num1: " << num1 << ", num2: " << num2 << ", num3: " << num3 << endl;

    // sizeof()函数，用法sizeof(数据)
    cout << "short变量，占用字节：" << sizeof(age) << endl;
    cout << "int变量，占用字节：" << sizeof(num1) << endl;
    cout << "long变量，占用字节：" << sizeof(num2) << endl;
    cout << "long long变量，占用字节：" << sizeof(num3) << endl;

    // 整型常量
    cout << "sizeof(10): " << sizeof(10) << " bytes" << endl;
    // 实型常量（浮点数）
    cout << "sizeof(10.0): " << sizeof(10.0) << " bytes" << endl;
    cout << "sizeof(10.0f): " << sizeof(10.0f) << " bytes" << endl;
    // 字符常量
    cout << "sizeof('A'): " << sizeof('A') << " bytes" << endl;
    // 字符串常量
    cout << "sizeof(\"A\"): " << sizeof("A") << " bytes" << endl;
    // 符号常量
    cout << "sizeof(PI): " << sizeof(PI) << " bytes" << endl;
    cout << "sizeof(count): " << sizeof(count) << " bytes" << endl;

    return 0;
}   