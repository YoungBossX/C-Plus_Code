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
 * 读文件与写文件步骤相似，但是读取方式相对于比较多
 * 
 * 读文件步骤如下：
 *  - 包含头文件 #include <fstream>
 *  - 创建流对象 ifstream ifs;
 *  - 打开文件并判断文件是否打开成功 ifs.open("文件路径",打开方式);
 *  - 读数据 四种方式读取
 *  - 关闭文件 ifs.close();
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
 *  - 读文件可以利用ifstream ，或者fstream类
 *  - 利用is_open函数可以判断文件是否打开成功
 *  - close 关闭文件 
 */

void func() {
    ifstream ifs;

    ifs.open("test.txt", ios::in);

    if (!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
    }

    // char buf[1024] = {0};
    // while(ifs >> buf) {
    //     cout << buf << endl;
    // }

    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf))) {
    //     cout << buf << endl;
    // }

    // string buf;
    // while (getline(ifs, buf)) {
    //     cout << buf << endl;
    // } 

    char c;
    while ((c = ifs.get()) != EOF) { // EOF end of file
        cout << c;
    }

    ifs.close();
}

int main() {
    func();

    return 0;
}