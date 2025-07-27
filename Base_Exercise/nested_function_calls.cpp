#include "iostream"

using namespace std;

/*
* 早上锻炼身体，每天的锻炼方案有3种：
* 1. 慢跑、俯卧撑、拉伸
* 2. 骑自行车、深蹲、跳绳
* 3. 游泳、仰卧起坐、拉伸
*
* 用函数的思想，模拟这些锻炼动作。
*/

void jog() {
    cout << "慢跑" << endl;
}

void pushUps() {
    cout << "俯卧撑" << endl;
}

void stretching() {
    cout << "拉伸" << endl;
}

void cycling() {
    cout << "骑自行车" << endl;
}

void squats() {
    cout << "深蹲" << endl;
}

void jumpRope() {
    cout << "跳绳" << endl;
}

void swimming() {
    cout << "游泳" << endl;
}

void sitUps() {
    cout << "仰卧起坐" << endl;
}

void plan1() {
    cout << "方案1：" << endl;
    jog();
    pushUps();
    stretching();
}

void plan2() {
    cout << "方案2：" << endl;
    cycling();
    squats();
    jumpRope();
}

void plan3() {
    cout << "方案3：" << endl;
    swimming();
    sitUps();
    stretching();
}

void exercise_plan(int num) {
    switch (num) {
        case 1:
            plan1();
            break;
        case 2:
            plan2();
            break;
        case 3:
            plan3();
            break;
        default:
            cout << "无效的方案编号" << endl;
    }
}

int main() {
    cout << "早上锻炼身体的方案：" << endl;
    cout << "1. 慢跑、俯卧撑、拉伸" << endl;
    cout << "2. 骑自行车、深蹲、跳绳" << endl;
    cout << "3. 游泳、仰卧起坐、拉伸" << endl;
    int choice;
    cout << "请选择锻炼方案（1-3）：";
    cin >> choice;
    exercise_plan(choice);
    
    return 0;
}   