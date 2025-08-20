/*
 * 主要针对C++泛型编程和ST技术做详细讲解，探讨C++更深层的使用
 *
 * 模板的概念
 *  - 模板就是建立通用的模具，大大提高复用性
 * 
 * 模板的特点
 *  - 模板不可以直接使用，它只是一个框架
 *  - 模板的通用并不是万能的
 * 
 * 学习目标：
 *  - 掌握类模板配合友元函数的类内和类外实现
 * 
 * 全局函数类内实现 - 直接在类内声明友元即可
 * 全局函数类外实现 - 需要提前让编译器知道全局函数的存在
 * 
 * 总结：
 *  - 建议全局函数做类内实现，用法简单，而且编译器可以直接识别
 */

#include "iostream"

using namespace std;

// 提前让编译器知道Person类存在
template<class T1, class T2>
class Person;

// 2.全局函数在类外实现
// 如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
// template<class T1, class T2> 
// void printPerson2(Person<T1, T2> & p); 
template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
    cout << "Name: " << p.m_Name << ", Age: " << p.m_Age << endl;
}

// 通过全局函数打印Person信息
template<class T1, class T2> 
class Person{
    // 全局函数配合友元，类内实现
    friend void printPerson1(Person<T1, T2> p) {
        cout << "Name: " << p.m_Name << ", Age: " << p.m_Age << endl;
    }

    // 2.全局函数配合友元，类外实现
    // 加空模板参数列表，让编译器知道这是一个函数模板，否则为普通函数声明，后面的全局函数为函数模板，不是同一个东西
    // 如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age) {
        this -> m_Name = name;
        this -> m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

// 1.全局函数在类内实现
void func1() {
    Person<string, int> p("XCC", 20);
    printPerson1(p);
}

void func2() {
    Person<string, int> p("XCC", 20);
    printPerson2(p);
}

int main() {
    func1();
    func2();

    return 0;
}