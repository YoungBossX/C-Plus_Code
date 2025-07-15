#include "iostream"

using namespace std;

int main(){
    // +=、-=、*=、/=、%=
    int num1 = 2;
    int num2 = num1 + 3;
    cout << "num2:" << num2 << endl;
    // +=，将变量本身进行加法操作，将结果再次赋值给变量本身
    num2 += 3;
    cout << "num2:" << num2 << endl; 
    // -=，将变量本身进行减法操作，将结果再次赋值给变量本身
    num2 -= 2;
    cout << "num2:" << num2 << endl;
    // *=，将变量本身进行乘法操作，将结果再次赋值给变量本身
    num2 *= 2;
    cout << "num2:" << num2 << endl;
    // /=，将变量本身进行除法操作，将结果再次赋值给变量本身
    num2 /= 3;
    cout << "num2:" << num2 << endl;
    // %=，将变量本身进行取余操作，将结果再次赋值给变量本身
    num2 %= 2;
    cout << "num2:" << num2 << endl; 

    // 作业
    int balance = 50;
    cout << "小明余额："<< balance << "元。" << endl;

    balance -= 5;
    cout << "购买奶茶花费5员，余额剩余："<< balance << "元。" << endl;

    balance += 10;
    cout << "转卖奶茶得到10元，余额剩余："<< balance << "元。" << endl;

    balance -= 2;
    cout << "购买彩票花费2元，余额剩余：" << balance << "元。" << endl;

    balance *= 2;
    cout << "彩票中奖余额翻倍，余额剩余：" << balance << "元。" << endl;

    return 0;
}   