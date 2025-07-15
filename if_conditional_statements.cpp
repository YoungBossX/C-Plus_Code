#include "iostream"

using namespace std;

int main(){
    /*
     * if(condition){
     *  code;
     *  code
     *  ...
     * }
     */
    
    cout << "今天发米了" << endl;
    int money;
    cout << "Please enter a number: ";
    cin >> money;
    // 开始逻辑判断
    if(money > 10000){
        // 满足条件就会执行这里面的代码
        cout << "买鸡腿去，花了100块！" << endl;
        money -= 100;
    }
    cout << "剩余金额：" << money << endl;

    // 作业
    cout << "欢迎来到儿童游乐场，儿童免费，成人收费！" << endl;
    cout << "请输入你的年龄：";

    int age;
    cin >> age;
    if(age < 18){
        cout << "您未成年，免费游玩，欢迎你小朋友！" << endl;
    }
    cout << "祝您游玩愉快！" << endl;

    return 0;
}   