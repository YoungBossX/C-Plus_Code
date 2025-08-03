#include "iostream"

using namespace std;

/*
 * 深浅拷贝是面试经典问题，也是常见的一个坑
 *
 * 浅拷贝：简单的赋值拷贝操作
 *
 * 深拷贝：在堆区重新申请空间，进行拷贝操作
 * 
 * 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数工防止浅拷贝带来的问题
 */

class Person {
public:
    int m_age;
    int* m_height;

    Person() {
        cout << "Person的默认构造函数调用" << endl;
    }

    Person(int age, int height) {
        m_age = age;
        m_height = new int(height);
        cout << "Person的有参构造函数调用" << endl;
    }
    // 自己实现拷贝构造函数，解决浅拷贝问题
    Person(const Person& p) {
        cout << "Person的拷贝构造函数调用" << endl;
        m_age = p.m_age;
        // m_height = p.m_height; 编译器默认实现就是这行代码
        // 深拷贝
        m_height = new int(*p.m_height);
    }

    ~Person() {
        if (m_height != nullptr) {
            delete m_height; // 释放堆区内存
            m_height = nullptr; // 避免悬空指针
        }
        cout << "Person的析构函数调用" << endl;
    }  
};

void func1() {
    Person p1(18, 180); 
    cout << "p1的年龄：" << p1.m_age << endl;
    cout << "p1的身高：" << *(p1.m_height) << endl;

    Person p2(p1); // 编译器提供的拷贝构造函数，会做浅拷贝操作（堆区的内存重复释放，p2释放一次，p1又释放一次），用深拷贝解决
    cout << "p2的年龄：" << p2.m_age << endl;
    cout << "p2的身高：" << *(p2.m_height) << endl; 
}

int main() {
    func1();

    return 0;
}