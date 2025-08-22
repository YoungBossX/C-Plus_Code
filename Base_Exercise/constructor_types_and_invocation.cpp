#include "iostream"

using namespace std;

/*
 * 1.构造函数分类
 *   按照参数分类分为：有参和无参构造（无参又称为默认构造函数）
 *   按照类型分类分为：普通构造和拷贝构造
 */

class Person {
public:
    int age;
    // 无参构造函数
    Person() {
        cout << "Person的无参构造函数调用。" << endl;
    }
    // 有参构造函数
    Person(int i) {
        age = i;
        cout << "Person的有参构造函数调用。" << endl;
    }
    // 拷贝构造函数
    Person(const Person& p) {
        // 将传入对象的所有属性拷贝到当前对象
        age = p.age;
        cout << "Person的拷贝构造函数调用。" << endl;
    }

    ~Person() {
        cout << "Person的析构函数调用。" << endl;
    }
};

int main() {
    // 括号法
    Person p1; // 默认构造函数的调用
    Person p2(10); // 有参构造函数的调用
    Person p3(p2); // 拷贝构造函数的调用
    // 注意事项：
    // 掉要默认构造函数的时候，不要加()，因为编译器会认为是一个函数的声明
    // Person p1();
    // void func();

    cout << "p2的年龄是：" << p2.age << endl;
    cout << "p3的年龄是：" << p3.age << endl;
    // 显示法
    Person p4;
    Person p5 = Person(10); // 有参构造函数的调用，相当于 Person p5(10);
    Person p6 = Person(p4); // 拷贝构造函数的调用，相当于 Person p6(p4);
    // Person(10); 匿名对象，放在=右边相当于给它取名字，当前行执行结束后，系统会立即回收掉匿名对象
    // cout << "xcc" << endl;
    // 注意事项：
    // 不要用一个拷贝构造函数初始化匿名对象，编译器会认为 Person(p5) === Person p5; 与前面的 Person p5 = Person(10); 重定义了，对象声明重复了
    // Person(p5);

    // 隐式转换法
    Person p7 = 10; // 相当于写了 Person p7 = Person(10); 有参构造
    Person p8 = p7; // 相当于写了 Person p8 = Person(p7); 拷贝构造

    return 0;
}