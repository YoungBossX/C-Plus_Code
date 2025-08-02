#include "iostream"

using namespace std;

/*
 * 默认情况下，C++编译器至少会给一个类添加3个函数：
 * 1. 默认构造函数（无参，函数体为空）
 * 2. 默认析构函数（无参，函数体为空）
 * 3. 默认拷贝构造函数，对属性进行值拷贝（值拷贝）
 *
 * 构造函数调用规则如下：
 * - 如果用户定义了有参构造函数，C++不再提供默认无参构造，但是会提供默认拷贝构造
 * - 如果用户定义了拷贝构造函数，C++不会再提供其他构造函数
 */

class Person {
public:
    int m_age;
    // 无参（默认）构造函数
    Person() {
        cout << "默认构造函数" << endl;
    }
    // 有参构造函数
    Person(int age) {
        m_age = age;
        cout << "有参构造函数" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p) {
        m_age = p.m_age;
        cout << "拷贝构造函数" << endl;
    }
    // 默认析构函数
    ~Person() {
        cout << "析构函数" << endl;
    }
};

void func1() {
    Person p1;
    p1.m_age = 18;
    Person p2(p1);
    cout << "p2的年龄：" << p1.m_age << endl;
}

void func2() {
    Person p1(28);
    Person p2(p1);

    cout << "p2的年龄：" << p2.m_age << endl;
}

int main() {
    func1();
    func2();

    return 0;
}