#include "iostream"
#include "random"

using namespace std;

int get_random_number(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(min, max);  

    int random_number = dis(gen);
    return random_number;
}

int main() {
    /*
     * 需求：提供一个1-100的随机数字，让用户猜测    
     * 1. 无限次机会
     * 2. 猜错了提示大了或者小了，猜对了程序结束
     */
   
    // 1. 得到一个1-100的随机数
    int num = get_random_number(1, 100);
    cout << num << endl;

    // 2. 提示用户输入数字进行猜测
    int guess_num;
    do {
        cout << "请输入一个猜测的数字：";
        cin >> guess_num;
        
        if (guess_num < num) {
            cout << "你猜的数字小了，请再试一次！" << endl;
        } else if (guess_num > num) {
            cout << "你猜的数字大了，请再试一次！" << endl;
        } else {
            cout << "恭喜你，猜对了！" << endl;
        }
    } while (guess_num != num);

    return 0;
}   