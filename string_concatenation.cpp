#include "iostream"

using namespace std;

int main(){
    string name = "XCC";
    string major = "电子信息";
    int age = 18;
    double height = 188.8;

    string msg = "我叫做：" + name + "，专业是：" + major + 
                 "，年龄：" + to_string(age) + 
                 "岁，身高：" + to_string(height) + "cm。";
 
    cout << msg << endl;

    return 0;
}   