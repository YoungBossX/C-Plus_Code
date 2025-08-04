#include "iostream"

using namespace std;

/*
 * C++中空指针也是可以调用成员函数的，但是要注意有没有用到this指针
 *
 * 如果用到this指针，需要加以判断保证代码的健壮性
 */

// 空指针调用成员函数
class Person {
public:
    int m_age;

    void show_class_name() {
        cout << "Person class" << endl;
    }

    void show_age() {
        if (this == nullptr) {
            cout << "this is a null pointer, cannot access member function." << endl;
            return; // 如果this是空指针，直接返回
        }

        cout << "Age: " << m_age << endl; // 在 m_age 前面都默认了添加 this->，当前对象的属性
    }
};

void func1() {
    Person *p = nullptr; // 空指针，对象没有实体

    p->show_class_name(); 
    // p->show_age();
}

void func2() {
    Person *p = nullptr; // 空指针，对象没有实体，一个空的值访问里面的属性

    // p->show_class_name(); 
    p->show_age();
}

int main() {
    func1();
    func2();

    return 0;
}