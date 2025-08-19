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
 * 类模板语法
 * 类模板作用：
 *  - 建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表。
 * 语法：
 *      template<typename T>
 *      类
 * 解释：
 *  - template --- 声明创建模板
 *  - typename --- 表面其后面的符号是一种数据类型，可以用class代替
 *  - T --- 通用的数据类型，名称可以替换，通常为大写字母
 * 
 * 总结：
 *  - 类模板和函数模板语法相似，在声明模板template后面加类，此类称为类模板。
 */

#include "iostream"

using namespace std;

template<class NameType, class AgeType> 
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

void func() {
    Person<string, int> p1("Tom", 20);
    p1.showPerson();
}

int main () {
    func();

    return 0;
}