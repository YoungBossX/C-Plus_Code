#include "iostream"

using namespace std;

/*
 * 在C++中，类内的成员变量和成员函数分开存储
 * 只有非静态成员变量才属于类的对象上
 */

// 成员变量和成员函数分开存储

// class Person{
// public:
         
// };

class Person{
public:
    char m; // 内存对齐要求，4个字节对齐
    int m_A; // 非静态成员变量，属于类的对象上
    static int m_B; // 静态成员变量，属于类本身，不属于对象

    void func() {} // 非静态成员函数，不属于类的对象上
    static void func2() {} // 静态成员函数，属于类本身，不属于对象
};

int Person::m_B = 0;

void func1() {
    Person p;
    // 空对象占用内存空间为：1个字节
    // C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    cout << "Size of Person: " << sizeof(p) << endl;
}

void func2() {
    Person p;
    cout << "Size of Person: " << sizeof(p) << endl;
}

int main() {
    // func1();
    func2();

    return 0;
}