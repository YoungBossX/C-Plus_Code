#include "iostream"

using namespace std;

int main(){
    /* 
     * if (条件)
     * {}
     * else if (条件)
     * {}
     * else if (条件)
     * ..
     * ..
     * ..
     * else
     * {}
     */
    bool like = false;
    bool dislike = false;

    if (like) {
        cout << "I like C++!" << endl;
    } else if (dislike) {
        cout << "I dislike C++!" << endl;
    } else {
        cout << "I have no opinion on C++." << endl;
    } 

    // 作业
    // 1. 定义一个 1~10 范围内的整数变量，作为被猜的数字
    int secret_number = 6; // 假设被猜的数字是 7
    // 2. 提示用户输入猜想
    cout << "请输入一个猜想的数字（1-10）：";
    int guess;
    cin >> guess;
    // 3. 使用 if-else 语句判断猜想是否正确
    if (guess == secret_number) {
        cout << "你猜对了， 真棒！" << endl;
    } else if (guess < secret_number) {
        cout << "你猜小了！" << endl;
    } else {
        cout << "你猜大了！" << endl;
    }
    
    return 0;
}   