#include "iostream"

using namespace std;

/*
 * C++ 类中的成员可以是另一个类的对象，称该成员为对象成员。
 * 
 */

// 类对象作为类成员
class Phone {
public:
    string m_pname;

    Phone(string pname) : m_pname(pname) {
        cout << "Phone构造函数被调用。" << endl;
    }

    ~Phone() {
        cout << "Phone析构函数被调用。" << endl;
    }
};

class Person {
public:
    string m_name;
    Phone m_phone; 

    // Phone m_phone = pname 隐式转换法
    Person(string name, string pname) : m_name(name), m_phone(pname) {
        cout << "Person构造函数被调用。" << endl;
    }

    ~Person() {
        cout << "Person析构函数被调用。" << endl;
    }
};

// 当其它类对象作为本类成员，构造时候先构造其它类对象，再构造自身，析构的顺序与构造相反


void func1() {
    Person p("XCC", "HuaWei");
    cout << "Name: " << p.m_name << ", Phone: " << p.m_phone.m_pname << endl;
}

int main() {
    func1();

    return 0;
}