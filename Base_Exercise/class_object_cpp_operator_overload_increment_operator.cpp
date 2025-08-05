#include "iostream"

using namespace std;

/*
 * 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
 *
 * 作用： 通过重载递增运算符，实现自己的整型数据
 * 
 * 总结： 前置递增返回引用，后置递增返回值
 * 
 */

class MyInteger {
    friend ostream& operator<<(ostream& out, MyInteger myint);

public:
    int m_Num;

	MyInteger() {
		m_Num = 0;
	}    

    // 重载前置++运算符，返回引用为了一直对一个数据进行递增操作
	MyInteger& operator++() {
		//先++
		m_Num++;
		//再返回
		return *this;
	}

    // 重载后置++运算符
    //void operator++(int) int代表占位参数，可以用于区分前置和后置递增
    // 先 记录当时结果
    // 后 递增
    // 最后将记录结果做返回
    MyInteger operator++(int) {
        MyInteger temp = *this;
        m_Num++;
        return temp;
    }
};

ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num << endl;
	return out;
}

void func1() {
    MyInteger myint;
    cout << "myint: " << myint;
}

void func2() {
    MyInteger myint;
    cout << "++myint: " << ++myint;
    cout << "myint: " << myint;
}

void func3() {
    MyInteger myint;
    cout << "myint++: " << myint++;
    cout << "myint: " << myint;
}

int main() {
    func1();
    func2();
    func3();

    return 0;
}