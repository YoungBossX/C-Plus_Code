#include <iostream>
#include <fstream>

using namespace std;

/*
 * 程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
 * 通过文件可以将数据持久化
 * C++中对文件操作需要包含头文件 <fstream>
 * 
 * 文件类型分为两种：
 *  - 文本文件：文件以文本的ASCII码形式存储在计算机中
 *  - 二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们
 * 
 * 操作文件的三大类：
 *  - ofstream：写操作
 *  - ifstream： 读操作
 *  - fstream ： 读写操作
 * 
 * 以二进制的方式对文件进行读写操作
 * 打开方式要指定为 ios::binary
 * 
 * 二进制方式写文件主要利用流对象调用成员函数 write
 * 函数原型：ostream& write(const char * buffer,int len);
 * 参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
 * 
 * 文件打开方式：
 * | 打开方式    | 解释                       |
 * |------------|---------------------------|
 * | ios::in    | 为读文件而打开文件           |
 * | ios::out   | 为写文件而打开文件           |
 * | ios::ate   | 初始位置：文件尾            |
 * | ios::app   | 追加方式写文件              |
 * | ios::trunc | 如果文件存在先删除，再创建    |
 * | ios::binary| 二进制方式                 |
 * 
 * 总结：
 *  - 文件输出流对象 可以通过write函数，以二进制方式写数据
 */

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void func () {
    ofstream ofs("person.txt", ios::out | ios::binary);
    // ofs.open("person.txt", ios::out | ios::binary);
    if (!ofs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }

    Person p1("XCC", 18);
    ofs.write((const char*)&p1, sizeof(p1));
    
    ofs.close();
}

int main() {
    func();

    return 0;
}