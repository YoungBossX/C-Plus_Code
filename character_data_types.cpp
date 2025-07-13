#include "iostream"
#include "limits"

using namespace std;

int main(){
    // char类型本质上是数字，通过ASCII表来映射
    char ch = 65; // char类型，1个字节，-128~127或0~255
    cout << "ch: " << ch << endl;

    char ch2 = 'a';
    cout << "ch2: " << ch2 + 1 << endl; 

    char ch3 = 'a' + 2;
    cout << "ch3: " << ch3 << endl; 

    cout << "char是否有符号: " << (numeric_limits<char>::is_signed ? "有符号" : "无符号") << endl;

    return 0;
}   