#include "iostream"

using namespace std;

/*
 * 常函数：
 * - 成员函数后加const后称为常函数
 * - 常函数内不可以修改成员属性
 * - 成员属性声明时加关键字mutable后，在常函数中依然可以修改
 *
 * 常对象：
 * - 声明对象前加const称该对象为常对象
 * - 常对象只能调用常函数
 */

class Person {
public:
    int m_A;
    mutable int m_B;

    Person(int a, int b) : m_A(), m_B() {} // 构造函数初始化成员变量

    // this指针的本质，是指针常量（指针的指向是不可以修改的）
    // 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    // const Person* const this; 
    void show_person() const { // 此const等于上面的第一个const
        // this -> m_A = 100;
        // this = nullptr;
        this -> m_B = 200; // 特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
        cout << "m_B = " << m_B << endl;
    }

    void func() {
        m_A = 100;
    }
};

// 常函数
void func1() {
    Person p(10, 20);
    p.show_person();
}

// 常对象
void func2() {
    const Person p(10, 20);
    // p.m_A = 100;
    p.m_B = 100; // m_B是特殊值，在常对象下也能修改

    // 常对象只能调用常函数
    p.show_person();
    // p.func(); // 常对象不可以调用普通成员函数，因为普通成员函数可以修改属性
} 

int main() {
    func1();
    func2();

    return 0;
}