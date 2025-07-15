#include "iostream"

using namespace std;

int main(){
    // 表达式? v1 : v2;
    int num1, num2;
    cout << "请输入num1的值：";
    cin >> num1;
    cout << "请输入num2的值：";
    cin >> num2;

    num1 > num2 ? cout << "num1大于num2" << endl : num1 < num2 ? cout << "num1小于num2" << endl : cout << "num1等于num2" << endl;

    // 作业
    int score1, score2;
    cout << "请输入小明第一次考试的成绩 (0-100): ";
    cin >> score1;
    cout << "请输入小明第二次考试的成绩 (0-100): ";
    cin >> score2;

    score1 > score2 ? cout << "小明第一次考试成绩更高，不买糖" << endl : (score1 < score2) ? cout << "小明第二次考试成绩更高， 买糖" << endl : cout << "小明两次考试成绩相同" << endl;

    return 0;
}   