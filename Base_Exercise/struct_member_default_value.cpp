#include "iostream"

using namespace std;

int main() {
    struct Student {
        string name;
        string major_code = "C++";
        int dormitory_num = 1;
    };

    struct Student stu1 = {"XCC"};
    struct Student stu2 = {"xcc", "Python", 2};

    cout << "姓名：" << stu1.name << endl;
    cout << "专业：" << stu1.major_code << endl;
    cout << "宿舍号：" << stu1.dormitory_num << endl;

    cout << "姓名：" << stu2.name << endl;
    cout << "专业：" << stu2.major_code << endl;
    cout << "宿舍号：" << stu2.dormitory_num << endl;

    // 作业
    struct Stu {
        string name;
        int age = 11;
        string address;
    };

    struct Stu students[5];

    for (int i = 0; i < 5; i++) {
        cout << "请输入第" << i + 1 << "位学生的姓名：";
        cin >> students[i].name;
        cout << "请输入第" << i + 1 << "位学生的地址：";
        cin >> students[i].address;
    }

    cout << "学生信息如下：" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "姓名：" << students[i].name << ", 年龄：" << students[i].age 
             << ", 地址：" << students[i].address << endl;
    }

    return 0;
}