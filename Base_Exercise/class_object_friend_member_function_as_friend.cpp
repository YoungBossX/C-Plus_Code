#include "iostream"

using namespace std;

/*
 * 在程序里，有些私有属性也想让类外特殊的某些函数或者类进行访问，就需要用到友元的技术
 *
 * 友元的目的是让一个函数或者类访问另一个类中私有成员
 *
 * 友元的关键字为 friend
 *
 * 友元的三种实现：
 * - 全局函数做友元
 * - 类做友元
 * - 成员函数做友元
 */

class Building; // 前置声明

class Person{
public:
    Person();
    void visit1(); // 让visit1函数访问Building类的私有成员
    void visit2(); // 让visit2函数不可以访问Building类的私有成员

    Building* building;

};

class Building{
    friend void Person::visit1();
public:
    string m_sitting_room;

    Building();

private:
    string m_bed_room; 
};

// 类外实现成员函数
Building::Building() {
    this->m_sitting_room = "客厅";
    this->m_bed_room = "卧室";
}

Person::Person() {
    this->building = new Building;
}

void Person::visit1() {
    cout << "visit1正在访问" << this->building->m_sitting_room << endl;
    cout << "visit1正在访问" << this->building->m_bed_room << endl;
}

void Person::visit2() {
    cout << "visit2正在访问" << this->building->m_sitting_room << endl;
    // cout << "visit2正在访问" << this->building->m_bed_room << endl;
}

void func() {
    Person person;
    person.visit1();
    person.visit2(); 
}

int main() {
    func();

    return 0;
}