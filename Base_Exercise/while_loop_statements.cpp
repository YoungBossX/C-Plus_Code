#include "iostream"

using namespace std;

// int i;
// int sum;

int main(){
    // 循环因子的控制
    // bool is_run = true;
    // int num = 0;

    // while (is_run) {
    //     cout << "hello" << endl;
    //     num++;
        
    //     if (num >= 5) {
    //         is_run = false; // 控制因子的更新
    //     }
    // }

    // int day = 1;
    // while (day <= 7) {
    //     cout << "今天是第 " << day << " 天" << endl;

    //     day++;
    // }

   //  作业：通过while循环，计算从1累加到100的和
    int i = 1;
    int sum = 0;

    while (i <= 100) {
        sum += i; // 累加
        i++; // 更新循环变量
    }

    cout << "从1累加到100的和是：" << sum << endl;

    return 0;
} 