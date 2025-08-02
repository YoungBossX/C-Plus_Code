#include "iostream"

using namespace std;

/*
 * C++中拷贝构造函数调用时机通常有三种情况：
 * 1. 使用一个已经创建完毕的对象来初始化一个新对象
 * 2. 值传递的方式给函数参数传值
 * 3. 以值方式返回局部对象
 */

class Person {
public:
    int m_age;

    Person() {
        cout << "Person默认构造函数调用。" << endl;
    }
    Person(int age) {
        m_age = age;
        cout << "Person带参数的构造函数调用。" << endl;
    }
    Person(const Person &p) {
        m_age = p.m_age;
        cout << "Person拷贝构造函数调用。" << endl;
    }

    ~Person() {
        cout << "Person析构函数调用。" << endl;
    }
};

void func1(const Person& p) {
    Person p_copy(p);
    cout << "func函数中的p_copy的年龄: " << p.m_age << endl;
}

// 值方式返回局部对象
Person func2() {
    Person p;
    cout << (int*)&p <<endl;
    return p; // 拷贝一个新的对象返回
}

void func3() {
    Person p = func2();
    cout << (int*)&p <<endl;
}

int main() {
    Person p1(10);
    Person p2(p1); 
    cout << "p2的年龄: " << p2.m_age << endl;

    func1(p2);
    func3();
    return 0;
}