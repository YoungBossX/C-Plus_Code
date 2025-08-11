#include "iostream"

using namespace std;

/*
 * 多态是C++面向对象三大特性之一
 *
 * 多态分为两类：
 * - 静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
 * - 动态多态: 派生类和虚函数实现运行时多态
 *
 * 静态多态和动态多态区别：
 * - 静态多态的函数地址早绑定  -  编译阶段确定函数地址
 * - 动态多态的函数地址晚绑定  -  运行阶段确定函数地址
 * 
 * 重写：函数返回值类型、函数名、参数列表、完全一致称为重写
 * 
 * 案例描述
 * 制作饮品的大致流程为：煮水 -  冲泡 - 倒入杯中 - 加入辅料
 * 
 * 利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
 */

class AbstractDrinking{
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//规定流程
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee : public AbstractDrinking {
public:
	void Boil() {
        cout << "煮农夫山泉" << endl;
    }

    void Brew() {
        cout << "冲泡咖啡" << endl;
    }

    void PourInCup() {
        cout << "倒入杯中" << endl;
    }

    void PutSomething() {
        cout << "加入糖和牛奶" << endl;
    }
};

class Tea : public AbstractDrinking {
public:
    void Boil() {
        cout << "煮矿泉水" << endl;
    }

    void Brew() {
        cout << "冲泡茶叶" << endl;
    }

    void PourInCup() {
        cout << "倒入杯中" << endl;
    }

    void PutSomething() {
        cout << "加入柠檬" << endl;
    }
};

void doWork(AbstractDrinking* abs) {
    abs->MakeDrink();

    delete abs;
}

void func() {
    doWork(new Coffee); // AbstractDrinking* abs = new Coffee;
    cout << "------------------------" << endl;
    doWork(new Tea); // AbstractDrinking* abs = new Tea;
}

int main() {
    func();

    return 0;
}