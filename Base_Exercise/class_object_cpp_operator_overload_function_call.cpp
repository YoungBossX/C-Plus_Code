#include "iostream"

using namespace std;

/*
 * 运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
 *
 * 函数调用运算符 ()  也可以重载
 * 由于重载后使用的方式非常像函数的调用，因此称为仿函数
 * 仿函数没有固定写法，非常灵活
 * 
 */

class MyPrint
{
public:
    // 重载函数调用运算符
	void operator()(string text)
	{
		cout << text << endl;
	}

};

// 由于使用起来非常类似于函数调用，因此称为仿函数
void func1()
{
	// 重载的（）操作符 也称为仿函数
	MyPrint myFunc;
	myFunc("hello world");
}

class MyAdd
{
public:
// 仿函数非常灵活，没有固定的写法
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};

void func2()
{
	MyAdd add;
	int ret = add(10, 10);
	cout << "ret = " << ret << endl;

	// 匿名对象调用  
	cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}

int main() {
    func1();
    func2();
    return 0;
}