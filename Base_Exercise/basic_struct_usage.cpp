#include "iostream"

using namespace std;

/*
 * 声明语法：
 * struct 结构体类型名
 * {
 *   成员类型 成员名;
 *   成员类型 成员名;
 *   ...
 *   ...
 * };
 * 
 * 特点：
 *      一个结构体类型，可以包含多个成员(类似数组元素)，每个成员类型不限
 *      可以做到一批不同类型的数据，混装在一个结构体内
 */

int main() {
    struct Student {
        string name; 
        int age;
        string gender;
    };

    // 结构体变量得声明，可以在前面带上struct关键字，也可以不带
    // 建议写上，可以清晰的知道变量是自定义结构体类型
    struct Student stu;
    stu = {"XCC", 20, "男"};

    // cout << stu <<endl; // 结构体变量是一个整体的包装，无法直接cout输出
    // 需要访问每一个成员进行输出，访问语法：结构体变量.成员名称
    cout << "姓名：" << stu.name << endl;
    cout << "年龄：" << stu.age << endl;
    cout << "性别：" << stu.gender << endl;

    struct Student stu1 = {"xcc", 18, "男"};
    cout << "姓名：" << stu1.name << endl;
    cout << "年龄：" << stu1.age << endl;
    cout << "性别：" << stu1.gender << endl;

    // 作业
    struct Stu {
        string name; 
        int age;
        string address;
    };

    struct Stu students[5];

    for (int i = 0; i < 5; i++) {
        cout << "请输入第" << i + 1 << "个学生的姓名：";
        cin >> students[i].name;
        cout << "请输入第" << i + 1 << "个学生的年龄：";
        cin >> students[i].age;
        cout << "请输入第" << i + 1 << "个学生的地址：";
        cin >> students[i].address;

        cout << "学生" << i + 1 << "信息录入完成。" << endl;
        cout << "姓名：" << students[i].name 
             << "，年龄：" << students[i].age 
             << "，地址：" << students[i].address << "。" << endl;
    }

    cout << "所有学生信息录入完成。" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "学生" << i + 1 << "信息：" 
             << "姓名：" << students[i].name 
             << "，年龄：" << students[i].age 
             << "，地址：" << students[i].address << "。" << endl;
    }

    return 0;
}