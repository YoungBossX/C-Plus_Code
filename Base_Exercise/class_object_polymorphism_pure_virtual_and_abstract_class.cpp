#include "iostream"

using namespace std;

/*
 * 多态是C++面向对象三大特性之一
 *
 * 多态分为两类：
 * - 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
 * - 动态多态: 派生类和虚函数实现运行时多态
 *
 * 在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
 * 因此可以将虚函数改为纯虚函数
 * 纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;
 * 当类中有了纯虚函数，这个类也称为抽象类
 * 
 * 抽象类特点：
 *  - 无法实例化对象
 *  - 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
 */

class Base{
public:
    // 纯虚函数
    // 只要有一个纯虚函数，这个类称为抽象类
    // 1.无法实例化对象
    // 2.抽象类的子类，必须要重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base{
public:
    virtual void func() {
        cout << "Son func" << endl;
    };
};

void func1() {
    Base* b = new Son();
    b->func();      

    delete b; 
}

int main() {
    func1();

    return 0;
}