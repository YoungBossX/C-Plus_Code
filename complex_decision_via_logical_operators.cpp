#include "iostream"

using namespace std;

int main(){
    // ! 
    int num = 0;

    if (!num) {
        cout << "num is true" << endl; 
    } else {
        cout << "num is false" << endl; 
    }

    // &&
    int age, height;
    cout << "请输入你的年龄：";
    cin >> age;
    cout << "请输入你的身高（cm）：";
    cin >> height;

    // 必须同时满足年龄小于18并且身高小于120cm才可以免费
    if (age < 18 && height < 120) {
        cout << "免费游玩！" << endl;
    } else {
        cout << "你需要购买门票！" << endl;
    }

    // || 满足年龄小于18或者身高小于120cm其中一个条件即可免费
    if (age < 18 || height < 120) {
        cout << "免费游玩！" << endl;
    } else {
        cout << "你需要购买门票！" << endl;
    }    

    return 0;
}   