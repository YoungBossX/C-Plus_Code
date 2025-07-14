#include "iostream"

using namespace std;

int main(){
    // 转义字符：将普通的字符使用\作为开头，将其含义进行转换，对照得到ASCII表的控制字符的功能
    // \n 换行符 \t 制表符 \r 回车符 \\ 反斜杠 \' 单引号 \" 双引号 \? 问号 \a 响铃 \b 退格符 \f 换页符 \v 垂直制表符
    cout << "hello \n world" << endl; 
    cout << "-------------------------------" << endl;
    // \t制表符演示，效果等同于键盘的Tab键，一个\t可以补充到8个字符位
    cout << "hello\tworld" << endl;
    cout << "hi\tworld" << endl;
    cout << "-------------------------------" << endl;
    // \r回车符演示，效果等同于键盘的Enter键，覆盖之前的内容
    // 注意：\r会将光标移动到行首，但不会换行
    cout << "hello\rworld" << endl;
    cout << "-------------------------------" << endl;
    cout << "\\" << endl;
    cout << "--------------------------------" << endl;
    // 将双引号和单引号的特殊效果消除，普通字符输出
    cout << "\" \'" << endl;
    cout << "-------------------------------" << endl;

    return 0;
}   