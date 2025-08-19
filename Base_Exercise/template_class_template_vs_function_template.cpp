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
 * 类模板与函数模板区别主要有两点：
 *  - 类模板没有自动类型推导的使用方式（新版本跟新，有自动类型推导）
 *  - 类模板在模板参数列表中可以有默认参数
 * 
 * 总结：
 *  - 类模板使用只能用显示指定类型方式（新版本跟新，有自动类型推导）
 *  - 类模板中的模板参数列表可以有默认参数
 */

#include "iostream"

using namespace std;

template<class NameType, class AgeType = int> 
class Person {
public:
    Person(NameType name, AgeType age) {
		this -> m_name = name;
		this -> m_age = age;
    }

    void showPerson() {
        cout << "Name: " << this -> m_name << ", Age: " << this -> m_age << endl;
    }

    NameType m_name;
    AgeType m_age;
};

void func1() {
    Person<string, int> p1("Tom", 20);
    p1.showPerson();
    Person p2("Jerry", 20);
    p2.showPerson();
}

void func2() {
    Person<string> p("XCC", 18);
    p.showPerson();
}

int main () {
    func1();
    func2();

    return 0;
}