#include "iostream"

using namespace std;

/*
 * 每一个非静态成员函数只会有一份函数实例，即多个同类型对象会共用一块代码。
 * 问题：这块代码是如何区分各个对象调用自己的呢？
 *
 * C++ 通过提供特殊的对象指针——this指针，解决上述问题。
 * this指针指向被调用的成员函数所属于的对象。
 * this指针是隐含在每一个非静态成员函数内的一种指针。
 * this指针无需定义，直接使用即可。
 *
 * this指针的用途：
 * - 当形参和成员变量同名时，可用 this 指针来区分
 * - 在类的非静态成员函数中返回对象本身，可使用 return *this
 */

class Person { 
public:
    int m_age;

    Person(int age) {
        // age = age; // 这里的age是形参，和成员变量同名，但并没有使用this指针，导致成员变量未被初始化，这三个age是一件事
        this->m_age = age; // 使用this指针来区分成员变量和形参
    }

    Person& person_add_age(Person &p) {
        this->m_age += p.m_age;

        // this为指向对象的指针，而*this指向的就是这个对象本体
        return *this; 
    }
};

// 1. 解决名称冲突
void func1() {
    Person p1(18);
    cout << "p1 age: " << p1.m_age << endl;
}
// 2. 返回对象本事用*this
void func2() {
    Person p1(10);
    Person p2(10);

    // 链式编程思想，可以无限追加
    p2.person_add_age(p1).person_add_age(p1);

    cout << "p2 age: " << p2.m_age << endl;
}

int main() {
    func1();
    func2();

    return 0;
}