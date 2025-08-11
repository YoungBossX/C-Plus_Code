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
 * 重写：函数返回值类型、函数名、参数列表、完全一致称为重写
 * 
 * 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
 * 
 * 解决方式：将父类中的析构函数改为虚析构或者纯虚析构
 * 
 * 虚析构和纯虚析构共性：
 *  - 可以解决父类指针释放子类对象
 *  - 都需要有具体的函数实现
 * 虚析构和纯虚析构区别：
 *  - 如果是纯虚析构，该类属于抽象类，无法实例化对象
 * 
 * 虚析构语法：
 *  - virtual ~类名(){}
 * 纯虚析构语法：
 *  - virtual ~类名() = 0;
 *  - 类名::~类名(){}
 * 
 * 总结：
 *  - 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
 *  - 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
 *  - 拥有纯虚析构函数的类也属于抽象类
 */

class Animal {
public:
    Animal() {
        cout << "Animal构造函数被调用" << endl;
    }

    virtual void speak() = 0;

    // 利用虚析构函数可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal() {
    //     cout << "Animal虚析构函数被调用" << endl;
    // }

    // 纯虚析构，需要声明也需要调用
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
};

Animal :: ~Animal() {
    cout << "Animal纯虚析构函数被调用" << endl;
}

class Cat : public Animal {\
public:
    Cat(string name) {
        cout << "Cat构造函数被调用" << endl;
        m_name = new string(name);
    }

    void speak() {
        cout << *m_name << "小猫在说话" << endl;
    }

    ~Cat() {
        if (m_name != nullptr) {
            cout << "Cat析构函数被调用" << endl;
            delete m_name;
            m_name = nullptr;
        }
    }

    string* m_name;
};

void func1() {
    Animal* animal = new Cat("WYZ");
    animal->speak();
    // 父类指针在析构时,不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete animal;
}

int main() {
    func1();

    return 0;
}