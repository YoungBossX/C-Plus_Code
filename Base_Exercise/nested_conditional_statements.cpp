#include "iostream"

using namespace std;

/*
 * 如果C语言喜欢C++，C++就去表白C语言
 *  如果天气好，就出去玩
 *  否则就待在家里
 * 否则就喜欢Python  
 */

int main(){
    // int love;
    // int weather;

    // cout << "C语言对C++的态度是怎么样的？1是喜欢，0是不喜欢：";
    // cin >> love;
    
    // if (love) {
    //     cout << "很高兴，C语言喜欢C++，C++也喜欢C语言！" << endl;
    //     cout << "看一下天气，今天天气怎么样？1是好，0是不好：";
    //     cin >> weather;

    //     if (weather) {
    //         cout << "今天是个好天气，带C++一起踏青去！" << endl;
    //     } else {
    //         cout << "今天天气不好，去看电影吧！" << endl;
    //     }
    // } else {
    //     cout << "C语言不喜欢C++！" << endl;
    //     cout << "去找Python吧！" << endl;
    // }

    // 作业
    int secret = 6;
    int guess;

    cout << "请输入第一次猜想的数字 (1~10): ";
    cin >> guess;

    if (guess == secret) {
        cout << "第一次就猜对了，你真棒！" << endl;
    } else {
        cout << "猜错了，再试一次！" << endl;
        cout << "请输入第二次猜想的数字 (1~10): ";
        cin >> guess;

        if (guess == secret) {
            cout << "第二次猜对了，你真棒！" << endl;
        } else {
            cout << "猜错了，最后一次机会！" << endl;
            cout << "请输入第三次猜想的数字 (1~10): ";
            cin >> guess;

            if (guess == secret) {
                cout << "第三次终于猜对了，你真棒！" << endl;
            } else {
                cout << "Sorry，全部猜错啦，我想的是：" << secret << endl;
            }
        }
    }
    
    return 0;
}   