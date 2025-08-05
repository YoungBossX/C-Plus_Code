#include "iostream"

using namespace std;

/*
 * 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
 *
 * 总结1：对于内置的数据类型的表达式的的运算符是不可能改变的
 * 总结2：不要滥用运算符重载
 * 
 */

// 加号运算重载
// 1.成员函数重载
class Person{
public:
    int m_a;
    int m_b;

    Person() {};

    Person(int a, int b) {
        this->m_a = a;
        this->m_b = b;
    }

    Person operator+(const Person &p) {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;
        return temp;
    }
};

// 2.全局函数重载
Person operator+(const Person &p1, const Person &p2) {
    Person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;
    return temp;
}

void func() {
    Person p1(10, 20);
    Person p2(10, 20);

    // 成员函数方式
    Person p3 = p1 + p2; // 本质为 p2.operaor+(p1)
    cout << "p3.m_a: " << p3.m_a << ", p3.m_b: " << p3.m_b << endl;

    // 全局函数方式
    Person p4 = operator+(p1, p2); // 本质为 operator+(p1, p2)
    cout << "p4.m_a: " << p4.m_a << ", p4.m_b: " << p4.m_b << endl;
}

int main() {
    func();

    return 0;
}