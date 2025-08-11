#include "iostream"

using namespace std;

/*
 * 多态是C++面向对象三大特性之一
 *
 * 多态分为两类：
 * - 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
 * - 动态多态: 派生类和虚函数实现运行时多态
 *
 * 静态多态和动态多态区别：
 * - 静态多态的函数地址早绑定  -  编译阶段确定函数地址
 * - 动态多态的函数地址晚绑定  -  运行阶段确定函数地址
 * 
 * 总结：
 * 动态多态满足条件：
 *  - 有继承关系
 *  - 子类重写父类中的虚函数
 * 动态多态使用条件：
 *  - 父类指针或引用指向子类对象
 * 
 * 重写：函数返回值类型、函数名、参数列表、完全一致称为重写
 * 
 * 如果函数地址在编译阶段就能确定，那么静态联编
 * 如果函数地址在运行阶段才能确定，就是动态联编
 */

class Animal{
public:
    // 虚函数
    virtual void speak() {
       cout << "动物在说话" << endl;
    }
};

class Cat : public Animal{
public:
    void speak() {
        cout << "小猫在说话" << endl;
    }
};

class Dog : public Animal{
public:
    void speak() {
        cout << "小狗在说话" << endl;
    }
};

// 地址早绑定，在编译阶段确定函数地址
// 如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void do_speak(Animal &animal) {
    animal.speak(); // Animal & animal = cat; C++中允许父子之间的类型转换，不需要强制转换，直接可以引用
}

void func1() {
    Cat cat;
    do_speak(cat);
}

void func2() {
    Dog dog;
    do_speak(dog);
}

int main (){
    func1();
    func2();

    return 0;
}