#include "iostream"
#include "cstring" // C语言的字符串库

using namespace std;

int main(){
    // ==相等 !=不等 <小于 >大于 <=小于等于 >=大于等于
    // 0 false 假 1 true 真
    int num1 = 3;
    int num2 = 5;
    bool result1 = num1 == num2; 
    bool result2 = num1 != num2;
    cout << "num1 == num2:" << result1 << endl; 
    cout << "num1 != num2:" << result2 << endl;

    cout << "3 < 5:" << (3 < 5) << endl;
    cout << "3 > 5:" << (3 > 5) << endl;
    cout << "3 <= 5:" << (3 <= 5) << endl;
    cout << "3 >= 5:" << (3 >= 5) << endl;

    // 字符串的比较
    // C语言风格字符串 char s[] char *s
    // C语言风格字符串，直接应用比较计算符，比较的是内存地址，而不是内容
    char s1[] = "hello";
    char *s2 = "hello";
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "\"a\" - \"b\": " << ("a" - "b") << endl; // 计算的是地址差
    cout << "\'a\' - \'b\': " << ('a' - 'b') << endl; // 计算的是字符的ASCII码差
    
    // strcmp进行比较，-1表示s1小于s2，0表示s1等于s2，1表示s1大于s2
    cout << "strcmp(s1, s2): " << strcmp(s1, s2) << endl;

    char s3[] = "a";
    char *s4 = "b";
    cout << "strcmp(s3, s4): " << strcmp(s3, s4) << endl;
    cout << "s3 - s4: " << (s3 - s4) << endl; // 计算的是地址差


    cout << "字符串字面量 c 是否大于 a：" << strcmp("c", "a") << endl;

    // C++风格字符串，string类型的都是C++风格字符串
    // 在比较中只要有一个C++风格字符串，就可以用比较运算符
    string s5 = "hello";
    char s6[] = "hello";
    cout << "s5 == s6: " << (s5 == s6) << endl;
    string s7 = "a";
    string s8 = "b";
    // cout << "s7 - s8: " << (s7 - s8) << endl; // C++风格字符串不能直接用减法运算符
    cout << "s7 + s8: " << s7 + s8 << endl; // C++风格字符串可以用加法运算符连接

    return 0;
}   