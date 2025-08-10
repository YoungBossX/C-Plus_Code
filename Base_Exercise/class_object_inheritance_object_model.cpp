#include "iostream"

using namespace std;

/*
 * 继承是面向对象三大特性之一
 *
 * 继承的语法：class 子类 : 继承方式  父类
 * 
 * 继承方式一共有三种：
 *      公共继承
 *      保护继承
 *      私有继承
 * 
 * 可利用开发人员命令提示工具查看对象模型（Visual Studio下可用，开发人员命令提示符）
 * 跳转盘符
 * 进入具体的文件路径下
 * 输入： cl /d1 reportSingleClassLayout查看的类名   所属文件名
 * 
 * 问题：从父类继承过来的成员，哪些属于子类对象中？
 * 父类中所有非静态成员属性都会被子类继承下去
 * 父类中私有成员属性 是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
 * 
 * 结论： 父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到
 */

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};

//公共继承
class Son :public Base
{
public:
	int m_D;
};

void func1()
{
	cout << "sizeof Son = " << sizeof(Son) << endl;
}

int main() {
	func1();

	return 0;
}