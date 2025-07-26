#include "iostream"

using namespace std;

int main() {
    struct Student {
        string name;
        int age = 20;
        string gender = "男";
    };

    struct Student stus[3] = {{"XCC"}, {"XCc"}, {"Xcc"}};
    struct Student* p_stu = stus; 
    
    cout << "数组中的第一个元素中记录的name是：" << p_stu->name << endl;
    cout << "数组中的第一个元素中记录的age是：" << p_stu->age << endl;
    cout << "数组中的第一个元素中记录的gender是：" << p_stu->gender << endl;
    cout << "数组中的第一个元素中记录的name是：" << p_stu[0].name << endl;
    cout << "数组中的第一个元素中记录的age是：" << p_stu[0].age << endl;
    cout << "数组中的第一个元素中记录的gender是：" << p_stu[0].gender << endl;

    //通过new操作符，自行申请结构体数组的空间（可以通过delete回收）
    struct Student* p = new Student[3] {{"XCC"}, {"XCc"}, {"Xcc"}};

    cout << "通过new操作符申请的第一个元素中记录的name是：" << p->name << endl;
    cout << "通过new操作符申请的第一个元素中记录的age是：" << p->age << endl;
    cout << "通过new操作符申请的第一个元素中记录的gender是：" << p->gender << endl;
    cout << "通过new操作符申请的第一个元素中记录的name是：" << p[0].name << endl;
    cout << "通过new操作符申请的第一个元素中记录的age是：" << p[0].age << endl;
    cout << "通过new操作符申请的第一个元素中记录的gender是：" << p[0].gender << endl;

    delete[] p;  // 释放动态申请的内存
    p = nullptr; // 避免悬空指针

    // 作业
    struct Stu {
        string name;
        int age;
        string address;
    };

    struct Stu* p_s = new Stu[5]; 

    for (int i = 0; i < 5; i++) {
        cout << "请输入第" << i + 1 << "位学生的姓名：";
        cin >> p_s[i].name;
        cout << "请输入第" << i + 1 << "位学生的年龄：";
        cin >> p_s[i].age;
        cout << "请输入第" << i + 1 << "位学生的地址：";
        cin >> p_s[i].address;
    }

    cout << "学生信息如下：" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "姓名：" << p_s[i].name << ", 年龄：" << p_s[i].age 
             << ", 地址：" << p_s[i].address << endl;
    }

    delete[] p_s;  // 释放动态申请的内存
    p_s = nullptr; // 避免悬空指针
    cout << "动态申请的内存已释放。" << endl;
    
    return 0;
}