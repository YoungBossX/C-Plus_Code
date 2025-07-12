#include "iostream"

using namespace std;

int main() {
    int bmi;
    bmi = 30; // 体重指数（BMI）值
    cout << "体重指数（BMI）值: " << bmi << endl;

    bmi = 26;
    cout << "经过一个月的减肥，现在的体重指数（BMI）值: " << bmi << endl;

    // 进行数学计算，+ - * /
    bmi = bmi - 2;
    cout << "经过一个月的减肥，BMI减少了2点，现在的体重指数（BMI）值: " << bmi << endl;

    // 作业
    int money = 50;
    cout << "小明余额：" << money << "元。" << endl;

    money = money - 5;
    cout << "购买冰淇淋花费5元，余额剩余：" << money << "元。" << endl;
    money = money + 10;
    cout << "转卖冰淇淋得到10元，余额剩余：" << money << "元。" << endl;
    money = money - 2;
    cout << "购买彩票花费2元，余额剩余：" << money << "元。" << endl;
    money = money * 2;
    cout << "彩票中奖余额翻倍，余额剩余：" << money << "元。" << endl;

    return 0;
}