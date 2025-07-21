#include <iostream>
#include <random>

using namespace std;

/*
 * 某公司，账户余额有1W元，给20名员工发工资。
 * 员工编号从1到20，从编号1开始，依次领取工资，每人可领取1000元
 * 领工资时，财务判断员工的绩效分(1-10)(随机生成)，如果低于5，不发工资，换下一位
 * 如果工资发完了，结束发工资大
 * 
 * 提示：
 * 使用循环对员工依次发放工资
 * continue用于跳过员工，break直接结束发工资
 */

int get_random_score(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    int total_money = 10000; 

    for (int id = 1; id <= 20; id++) {

        // 如果工资发完了结束发工资
        if (total_money <= 0) {
            cout << "工资发放完成，下一个月再来！" << endl;
            break;
        }

        // 随机得到绩效分
        int score = get_random_score(1, 10);
        if (score < 5) {
            cout << "不好意思，员工" << id << "绩效分为" << score << "，小于" << 5 << "，不发工资，下一位!" << endl;
            continue;
        }
        else {
            cout << "员工" << id << "绩效分为" << score << "，大于等于" << 5 << "，发放工资1000元，当前余额：" << total_money << "元" << endl; 
            total_money -= 1000;
        }


    }

    return 0;
}