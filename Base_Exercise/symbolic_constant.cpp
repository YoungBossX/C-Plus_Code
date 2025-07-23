#include "iostream"

using namespace std;

// 符号常量：#define 名称（标识符） 常量值，定义在代码的头部
// 符号常量的定义，不需要分号结尾
#define NAME "周杰伦"
#define AGE 18
#define HEIGHT 180
#define WEIGHT 88.8
#define FAT_BMI 28
#define J2C_RATE 4.19

int main() {
    cout << "FAT_BMI: " << FAT_BMI << endl;
    cout << "焦耳转卡路里需要除以: " << J2C_RATE << endl;
    cout << "我是" << NAME << "，今年" << AGE << "岁。" << endl;
    cout << "我的身高是" << HEIGHT << "cm，体重是" << WEIGHT << "kg。" << endl;
    return 0;
}