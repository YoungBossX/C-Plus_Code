#include "iostream"

using namespace std;

/*
 * 静态成员就是在成员变量和成员函数前加上关键字 static，称为静态成员
 *
 * 静态成员分为：
 *
 * 静态成员变量
 *   - 所有对象共享同一份数据
 *   - 在编译阶段分配内存
 *   - 类内声明，类外初始化
 *
 * 静态成员函数
 *   - 所有对象共享同一个函数
 *   - 静态成员函数只能访问静态成员变量
 */

// 静态成员变量
class Person {
public:
    static int m_A;
    int m_C;

    static void func1() {
        m_A = 100; // 静态成员函数可以访问静态成员变量
        // m_C = 200; // 静态成员函数不能访问非静态成员变量，无法区分到底是哪个对象的m_B属性
        cout << "静态成员变量m_A：" << m_A << endl;
        cout << "静态成员函数1。" << endl;
    }

private:
    // 静态成员变量也是有访问权限的
    static int m_B;
    // 静态成员函数也是有访问权限的
    static void func2() {
        cout << "静态成员函数2。" << endl;
    }
};

int Person::m_A = 10;
int Person::m_B = 100;

void func1() {
    Person p1;
    cout << p1.m_A << endl;

    Person p2;
    p2.m_A = 20;
    cout << p1.m_A << endl;

}

void func2() {
    // 静态成员变量不属于某个对象，所有对象都共享同一份数据
    // 因此静态成员变量有两种访问方式
    // 1. 通过对象进行访问
    // Person p1;
    // cout << p1.m_A << endl;
    // 2. 通过类名进行访问
    cout << Person::m_A << endl;
    // cout << Person::m_B << endl; // 静态成员变量是私有的，不能通过类名访问也不可以通过对象访问
}

void func3() {
    // 1. 通过对象访问静态成员函数
    Person p1;
    p1.func1();
    // 2. 通过类名访问静态成员函数
    Person::func1();

    // Person::func2(); // 静态成员函数是私有的，不能通过类名访问也不可以通过对象访问
}

int main() {
    // func1();
    // func2();

    func3();

    return 0;
}