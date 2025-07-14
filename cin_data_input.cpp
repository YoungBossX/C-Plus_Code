#include "iostream"

using namespace std;

int main(){
    // cin >> 变量
    int num1;
    cout << "请输入一个整数：";
    cin >> num1;

    double num2;
    cout << "请输入一个实型数字：";
    cin >> num2;

    char ch;
    cout << "请输入一个字符：";
    cin >> ch;

    string str;
    cout << "请输入一个字符串：";
    cin >> str;

    cout << "输入的整数值：" << num1 << endl;
    cout << "输入的实型数字：" << num2 << endl;
    cout << "输入的字符：" << ch << endl;
    cout << "输入的字符串：" << str << endl;

    // cin作业
    string name;
    double height;
    int age;

    cout << "请输入姓名：";
    cin >> name;
    cout << "请输入身高（CM）：";
    cin >> height;
    cout << "请输入年龄：";
    cin >> age;
    cout << "-----------------------" << endl;
    cout << "姓名：" << name << endl;
    cout << "身高：" << height << "CM" << endl;
    cout << "年龄：" << age << "岁" << endl;

    return 0;
}   