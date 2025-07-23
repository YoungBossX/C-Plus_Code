#include "iostream"

using namespace std;
using U_short = unsigned short;
using U_long = unsigned long;
using U_ll = unsigned long long;

#define PI 3.14159 

const int count = 10;

int main() {
    // 有符号：signed（可选），无符号：unsigned（必写）
    signed int num1 = 10;
    int num2 = -10;
    cout << "num1: " << num1 << ", num2: " << num2 << endl;

    unsigned int num3 = -30;
    cout << "num3: " << num3 << endl;

    // long 无符号
    unsigned long num4 = 50;
    // 无符号int、short、long、long long有快捷写法
    U_short num5 = 100;
    U_long num6 = 200;
    U_ll num7 = 300;
    cout << "num4: " << num4 << ", num5: " << num5 << ", num6: " << num6 << ", num7: " << num7 << endl;
    return 0;
}   