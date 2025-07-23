#include "iostream"
#include <random>

using namespace std;

int get_random_number(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(min, max);  

    int random_number = dis(gen);
    return random_number;
}

int main() {
    int total_days = 30;
    for (int day = 1; day <= total_days; day++) {
        cout << "第" << day << "天：送花 -> 说喜欢 -> 邀请看电影" << endl;

        // 10%的概率生气
        if (get_random_number(1, 10) == 1) {
            cout << "小美生气了，表白计划彻底停止。" << endl;
            break;
        }

        // 50% 概率小美不高兴
        if (get_random_number(1, 2) == 1) {
            cout << "小美今天不高兴，今天流程结束，第二天继续。" << endl;
            continue;
        }

        cout << "小美很开心，表白，一起去看电影！" << endl;
    }

    cout << "表白计划结束！" << endl;

    return 0;
}