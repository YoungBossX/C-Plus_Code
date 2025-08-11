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
 * 案例描述：
 *  - 电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）
 *  - 将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和AMD厂商
 *  - 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
 *  - 测试时组装三台不同的电脑进行工作
 */

class CPU{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};

class VideoCard
{
public:
	//抽象的显示函数
	virtual void display() = 0;
};

class Memory
{
public:
	//抽象的存储函数
	virtual void storage() = 0;
};

class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Intel的CPU开始计算了！" << endl;
	}
};

class IntelVideoCard : public VideoCard {
public:
    void display()
    {
        cout << "Intel的显卡开始显示了！" << endl;
    }
};

class IntelMemory : public Memory {
public:
    void storage()
    {
        cout << "Intel的内存条开始存储数据了！" << endl;
    }
};

class AMDCPU : public CPU {
public:
    void calculate()
    {
        cout << "AMD的CPU开始计算了！" << endl;
    }
};

class AMDVideoCard : public VideoCard {
public:
    void display()
    {
        cout << "AMD的显卡开始显示了！" << endl;
    }
};

class AMDMemory : public Memory {
public:
    void storage()
    {
        cout << "AMD的内存条开始存储数据了！" << endl;
    }
};

class Computer {
private:
    CPU* m_cpu;
    VideoCard* m_videoCard;
    Memory* m_memory;
public:
    Computer(CPU* c, VideoCard* v, Memory* m) : m_cpu(c), m_videoCard(v), m_memory(m) {}

    void work()
    {
        m_cpu->calculate();
        m_videoCard->display();
        m_memory->storage();
    }

    ~Computer()
    {
        if (m_cpu != nullptr) {
			delete m_cpu;
			m_cpu = nullptr;
		}

        if (m_videoCard != nullptr) {
            delete m_videoCard;
            m_videoCard = nullptr;
        }

        if (m_memory != nullptr) {
            delete m_memory;
            m_memory = nullptr;
        }
    }
};

void func() {
    CPU* intel_cpu_1 = new IntelCPU;
    VideoCard* intel_video_1 = new IntelVideoCard;
    Memory* intel_memory_1 = new IntelMemory;

    cout << "第一台电脑开始工作：" << endl;
    // 创建第一台电脑
    Computer* computer_1 = new Computer(intel_cpu_1, intel_video_1, intel_memory_1);
    computer_1 -> work();
    delete computer_1;

    CPU* amd_cpu_2 = new AMDCPU;
    VideoCard* amd_video_2 = new AMDVideoCard;
    Memory* amd_memory_2 = new AMDMemory;

    cout << "-----------------------" << endl;
	cout << "第二台电脑开始工作：" << endl;
	//第二台电脑组装
	Computer * computer_2 = new Computer(amd_cpu_2, amd_video_2, amd_memory_2);
	computer_2 -> work();
	delete computer_2 ;

    CPU* amd_cpu_3 = new AMDCPU;
    VideoCard* intel_video_3 = new IntelVideoCard;
    Memory* amd_memory_3 = new AMDMemory;

    cout << "-----------------------" << endl;
	cout << "第三台电脑开始工作：" << endl;
	//第三台电脑组装
	Computer * computer_3 = new Computer(amd_cpu_3, intel_video_3, amd_memory_3);
	computer_3 -> work();
	delete computer_3;
}

int main() {
    func();

    return 0;
}