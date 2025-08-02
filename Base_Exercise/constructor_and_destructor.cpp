#include "iostream"

using namespace std;

//对象的初始化和清理
//1、构造函数 进行初始化操作
class Person;
class Person {
public:
    // 构造函数
    // 没有返回值，不用写void
    // 函数名与类名相同
    // 构造函数可以有参数，可以发送重载
    // 创建对象的时候，构造会自动调用，而且只调用一次
    Person() {
        cout << "Person的构造函数调用" << endl;
    }

    // 2、析构函数 进行清理的操作
    // 没有返回值，不用写void
    // 函数名与类名相同，在名称前加 ~
    // 析构函数没有参数，不能重载
    // 对象在销毁前，会自动调用析构函数，而且只调用一次
    ~Person() {
        cout << "Person的析构函数调用" << endl;
    }
};

int main() {
    // 构造和析构都是必须有的实现，如果不提供，编译器会提供一个空实现的构造和析构
    class Person person;
    
    return 0;
}