#include "iostream"

using namespace std;

int main(){
    // 单目（只有一个操作数）操作符：+、-
    int num1 = +10; // 正号
    int num2 = -10; // 负号
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    // 双目（有两个操作数）操作符：+、-、*、/、%
    int num3 = 5 + 5;
    int num4 = 5 - 3;
    int num5 = 5 * 5;
    int num6 = 10 / 3;
    int num7 = 10 % 3;

    cout << "num3 (5 + 5): " << num3 << endl;
    cout << "num4 (5 - 3): " << num4 << endl;
    cout << "num5 (5 * 5): " << num5 << endl;
    cout << "num6 (10 / 3): " << num6 << endl;
    cout << "num7 (10 % 3): " << num7 << endl;

    // 单目操作符：++、--
    int num8 = 5;
    int num9 = ++num8; // 前置递增（+1），在赋值语句（=）之前，先执行加1的操作，优先级大于=
    cout << "num8:" << num8 << endl;   
    cout << "num9:" << num9 << endl; 
    int num10 = 5;
    int num11 = num10++;
    cout << "num10:" << num10 << endl;
    cout << "num11:" << num11 << endl; 
    int num12 = 5;
    int num13 = --num12; // 前置递减（-1），在赋值语句（=）之前，先执行减1的操作，优先级大于=
    cout << "num12:" << num12 << endl;
    cout << "num13:" << num13 << endl;
    int num14 = 5;
    int num15 = num14--; // 后置递减（-1），在赋值语句（=）之后，先执行赋值操作，再执行减1的操作,优先级小于=
    cout << "num14:" << num14 << endl;
    cout << "num15:" << num15 << endl;

    return 0;
}   