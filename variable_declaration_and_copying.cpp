#include "iostream"

using namespace std;

int main() {
    // 变量的声明（定义），变量类型 变量名;
    int age; // 整型变量
    int weight; // 整型变量
    float height; // 浮点型变量
    char gender; // 字符型变量
    string name; // 字符串变量
    // 变量的赋值，变量名 = 变量值;
    age = 18; // 将 18 赋值给 age
    weight = 88; // 将 88 赋值给 weight
    height = 180.8; // 将 180.8 赋值给 height
    gender = 'm';
    name = "XCC"; 

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Gender: " << gender << endl;
    cout << "Name: " << name << "，年纪" << age << endl;
    cout << "Name: " << name << "，体重" << height << endl;
    cout << "Name: " << name << "，性别" << gender << endl; 
    cout << "我叫" << name << "，今年" << age << "岁。" << endl;
    cout << "身高" << height << "cm，体重" << weight << "KG。" << endl;
    return 0;
}
