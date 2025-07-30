#include "iostream"

using namespace std;

/*
 * 设计一个类，可以封装学生实体的属性和行为
 * 属性（类的成员变量）：学号、姓名、年龄、地址
 * 行为（类的成员方法（函数））：自我介绍（说出自己的属性）
 */

class Student;
class Student { // class就是一个设计图纸
public: // 访问修饰符号
    // 属性
    int id;
    string name;
    int age;
    string addr;

    void say_hi() const { 
        cout << "我是：" << name << "，id：" << id << "，年龄：" << age << "岁，地址：" << addr << endl;
    }
};

class Animal;
class Animal {
public:
    string species; // 物种
    string gender;  // 性别
    double weight;  // 体重（kg）

    void self_introduce() const {
        cout << "我是：" << species << "，性别：" << gender << "，体重：" << weight << "kg" << endl;
    }   
};

int main() {
    // 使用这个类，就是得到类对象（类类型的变量）来干活，就不叫变量了，本质还是变量
    // 方式1：先声明一个类对象，然后对类对象的成员变量赋值
    class Student stu; // 声明了Student类型的一个变量（就是类对象）
    stu.id = 1;
    stu.name = "XCC";
    stu.age = 18;
    stu.addr = "hangzhou";

    stu.say_hi();

    // 方式2：声明和赋值同步
    class Student stu2 = {2, "Xcc", 19, "hunan"};

    stu2.say_hi();

    // 方式3：变种写法（更快捷）
    class Student stu3{3, "xcc", 20, "yongxing"};
    stu3.say_hi();

    // 作业
    class Animal cat{"猫", "公", 6.6};
    class Animal dog{"狗", "公", 18.8};
    class Animal robbit{"兔子", "公", 8.8};

    cat.self_introduce();
    dog.self_introduce();
    robbit.self_introduce();

    return 0;
}