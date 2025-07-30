#include "iostream"

using namespace std;

/*
 * - 访问修饰符 应用在成员上，对成员进行权限保护
 * - 在类的设计阶段（类内部），没有任何限制
 * - 基于类产生的类对象，是否能访问成员，被访问修饰符控制
 * - public：公开
 * - private：私有
 */

class WuKong;
class WuKong {
// 访问修饰符 public公开 private私有
public: // 在内部没什么用
    int id;
    string name;

    WuKong(int id, string name) : id(id), name(name) {}

    void say_hi() const {
        cout << "id: " << id << ", name: " << name << ", money: " << money << endl;
    }

    void fight() {
        cout << "打小怪了，打完增加游戏币！" << endl;
        add_money();
    }

    void action() {
        cout << "行动，做任务完成！" << endl;
        add_money();
    }

    void show_money() const {
        cout << "游戏币剩余：" << money << endl;
    }

private:
    int money = 0;

    void add_money() {
        money += 1000;
    }
};

int main() {
    // class WuKong wk{1, "悟空"}; // 声明了 private 成员 money，默认聚合初始化不再适用

    // class WuKong wk;
    // wk.id = 1;
    // wk.name = "悟空";

    class WuKong wk{1, "悟空"};

    wk.say_hi();
    wk.fight();
    wk.action();
    wk.show_money();

    return 0;
} 