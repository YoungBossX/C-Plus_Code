#include "iostream"

using namespace std;

int main() {
    struct Student {
        string name;
        int age;
        string gender;
    };
    
    // 先创建一个标准的结构体对象（静态内存管理）
    struct Student stu1 = {"xcc", 18, "男"};
    // 创建结构体的指针，指向结构体对象的地址
    struct Student* p_stu1 = &stu1;
    // 通过指针访问结构体成员，要使用的符号是：->
    cout << "姓名: " << p_stu1->name << ", 年龄: " << p_stu1->age << ", 性别: " << p_stu1->gender << endl;

    // 通过new操作符，申请结构体空间
    struct Student* p_stu2 = new Student {"XCC", 20, "男"};
    // 通过指针访问动态分配的结构体成员
    cout << "姓名: " << p_stu2->name << ", 年龄: " << p_stu2->age << ", 性别: " << p_stu2->gender << endl;

    // 释放动态分配的内存
    delete p_stu2;
    p_stu2 = nullptr; // 避免悬空指针

    return 0;
}