#include "iostream"

using namespace std;

int main() {
    struct Student {
        string name;
        int age;
        string gender;
    };

    struct Student arr1[3];

    arr1[0] = {
        "XCC",
        18,
        "男"
    };

    arr1[1] = {
        "XCc",
        19,
        "男"
    };

    arr1[2] = {
        "Xcc",
        20,
        "男"
    };

    for (int i = 0; i < 3; i++) {
        cout << "姓名: " << arr1[i].name << ", 年龄: " << arr1[i].age << ", 性别: " << arr1[i].gender << endl;
    }

    // 数组的声明和赋值同步写法
    struct Student arr2[2] = {
        {"xcc", 18, "男"},
        {"xCc", 19, "男"}
    };

    for (int i = 0; i < 2; i++) {
        cout << "姓名: " << arr2[i].name << ", 年龄: " << arr2[i].age << ", 性别: " << arr2[i].gender << endl;
    }

    // 作业
    struct Stu {
        string name;
        int age;
        string address;
    };

    struct Stu students[5];

    for (int i = 0; i < 5; i++) {
        cout << "请输入第" << i + 1 << "位学生的姓名：";
        cin >> students[i].name;
        cout << "请输入第" << i + 1 << "位学生的年龄：";
        cin >> students[i].age;
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