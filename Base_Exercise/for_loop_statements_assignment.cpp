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

int main () {
    // 1. 生成1~10的随机数
    int num = get_random_number(1, 10);
    cout << "生成的随机数是: " << num << endl;

    // 2. 提示用户输入数字进行猜测
    int guess_num;
    cout << "请猜一个 1~10 的数字：";

    // 3. 判断用户猜测的数字是否正确
    for (bool is_continue = true;is_continue;) {
        cin >> guess_num;

        if (guess_num < num) {
            cout << "你猜的数字小了，请重新猜测：";
        } else if (guess_num > num) {
            cout << "你猜的数字大了，请重新猜测：";
        } else {
            cout << "恭喜你猜对了！" << endl;
            is_continue = false;
        }
    }

    return 0;
}