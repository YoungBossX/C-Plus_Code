#include "iostream"

using namespace std;

int main() {
    /*
     * 细节点：
     * 1.外层循环完成5天的减肥
     * 2.内层循环进行：3个俯卧撑（3次完成减少1斤体重）、3次400米冲刺（3次完成减少1斤体重）
     * 3.过程中要累计体重减少
     */

    int total_days = 5;    // 共减肥5天
    int total_pushups = 3; // 每天3个俯卧撑
    int total_runs = 3;    // 每餐后3次400米冲刺
    int count_weights = 0;       // 累计减少体重的斤数
    int day = 1;
    
    cout << "有点胖需要减掉10斤体重，计划5天，每天2斤体重。加油！" << endl;

    while (day <= total_days) {
        cout << "今天是减肥的第" << day << "天！" << endl;

        int pushup = 1;
        while (pushup <= total_pushups) {
            cout << "开始减肥第" << day << "天的第" << pushup << "个俯卧撑！" << endl;
            pushup++;
        }

        count_weights++;
        cout << "减肥第" << day << "天的" << total_pushups << "个俯卧撑做完，" << "体重减少1斤，" << "目前累计减少体重：" << count_weights << "斤！" << endl;

        int run = 1;
        while (run <= total_runs) {
            cout << "开始减肥第" << day << "天的第" <<  run << "批次400米冲刺跑！" << endl;
            run++;   
        }

        count_weights++;
        cout << "减肥第" << day << "天的" << run << "批次400米冲刺跑完，" << "体重减少1斤，" << "目前累计减少体重：" << count_weights << "斤！" << endl;
        cout << endl;
        day++;
    }

    cout << total_days << "天减肥完成，体重累计减少：" << count_weights << "斤！" << endl;

    return 0;
}   