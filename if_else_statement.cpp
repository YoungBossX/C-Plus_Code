#include "iostream"

using namespace std;

int main(){
    /*
     * if (判断)
     * {
     *   ...
     * }
     * else
     * {
     *  ...
     * }
     */
    int love;
    cout << "请输入你对我的爱，喜欢扣1，不喜欢扣0: ";
    cin >> love;
    if (love == 1) {
        cout << "我也爱你！" << endl;
    } 
    else {
        cout << "没关系，再见！" << endl;
    }

    // 作业
    int height;
    cout << "欢迎来到动物园。" << endl;
    cout << "请输入你的身高（cm）：";
    cin >> height;

    if (height >= 120) {
        cout << "您的身高超出120cm，游玩需要购票10元。" << endl;
    } else {
        cout << "您的身高未超出120cm，可以免费游玩。" << endl;
    }
    cout << "祝您游玩愉快。" << endl;

    return 0;
}   