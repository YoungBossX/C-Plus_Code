#include "iostream"

using namespace std;

/*
 * 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
 *
 * 作用：重载关系运算符，可以让两个自定义类型对象进行对比操作
 * 
 */

class Person{
public:
    string m_name;
    int m_age;

    Person(string name, int age) {
        this -> m_name = name;
        this -> m_age = age;
    };

    bool operator==(Person& p) {
        if (this->m_name == p.m_name && this->m_age == p.m_age) {
            return true;
        } else {
            return false;
        }
    }

    bool operator!=(Person& p) {
        if (this->m_name != p.m_name || this->m_age != p.m_age) {
            return true;
        } else {
            return false;
        }
    }
};

void func() {
    Person p1("XCC", 20);
    Person p2("xcc", 18);

    if (p1 == p2) {
        cout << "p1和p2是同一个人！" << endl;
    } else {
        cout << "p1和p2不是同一个人！" << endl;
    }

    if (p1 != p2) {
        cout << "p1和p2不是同一个人！" << endl;
    } else {
        cout << "p1和p2是同一个人！" << endl;
    }
}

int main() {
    func();
    return 0;
}