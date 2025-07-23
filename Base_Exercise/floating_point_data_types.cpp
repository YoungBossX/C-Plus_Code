#include "iostream"

using namespace std;

int main(){
    // float单精度浮点数，4个字节，6~7位有效位数，有效位包括整数位、小数点、小数位
    float num1 = 1234567890;
    float num2 = 1.234567890; 

    cout << fixed; // 设置小数显示
    // cout << left; // 设置左对齐
    cout.width(20); // 设置输出宽度为20
    cout << "num1: " << num1 << "，字节数："<< sizeof(num1) << " bytes" << endl;
    cout << "num2: " << num2 << "，字节数："<< sizeof(num2) << " bytes" << endl;

    // double双精度浮点数，8个字节，15~16位有效位数，有效位包括整数位、小数点、小数位
    double num3 = 1234567890.1234567890;
    cout << "num3: " << num3 << "，字节数："<< sizeof(num3) << " bytes" << endl;
    // long double长精度（多精度）浮点数，16个字节，18~19位有效位数，有效位包括整数位、小数点、小数位
    long double num4 = 1234567890.1234567890;
    cout << "num4: " << num4 << "，字节数："<< sizeof(num4) << " bytes" << endl;
 
    return 0;
}   