#include "iostream"

using namespace std;

/*
 * 需要实现：主菜单函数、查询函数、存款函数、取款函数，共4个函数
 * 1. 启动要求输入用户名
 * 2. 启动后显示主菜单，要求用户输入选择
 * 3. 基于用户选择，提供相应功能
 * 4. 每一个功能内都能显示余额和用户名
 * 5. 每一个功能结束后，都会返回主菜单，当用户输入退出或输入错误程序才退出
 */

void query_money(string* name, int* const money) {
    // 查询余额的函数
    cout << "------------------查询余额----------------" << endl;
    cout << *name << "，您好，您的余额剩余：" << *money << "元" << endl;
}

void save_money(const string* const name, int* const money, int num) {
    cout << "------------------存款----------------" << endl;
    cout << *name << "，您好，您存款" << num << "元" << endl;
    *money += num; 
    cout << "您好，您的余额剩余：" << *money << "元" << endl;
}

void get_money(const string* const name, int* const money, int num) {
    cout << "------------------取款----------------" << endl;
    cout << *name << "，您好，您取款" << num << "元" << endl;
    *money -= num;
    cout << "您好，您的余额剩余：" << *money << "元" << endl; 
}

int menu(const string* const name) {
    cout << *name << "您好，欢迎来到银行。请选择操作：" << endl;
    cout << "1. 查询余额\t[输入1]" << endl;
    cout << "2. 存款\t\t[输入2]" << endl;
    cout << "3. 取款\t\t[输入3]" << endl;
    cout << "4. 退出\t\t[输入4]" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    return choice;
}

int main() {
    string name;
    cout << "请输入您的用户名：";
    cin >> name;

    int* money = new int(500000);

    bool is_run = true;
    while(is_run) {
        int choice = menu(&name);
        switch(choice) {
            case 1:
                query_money(&name, money);
                break;
            case 2: 
                int num_for_save_money;
                cout << "请输入你要存多少钱：";
                cin >> num_for_save_money;
                save_money(&name, money, num_for_save_money);
                break;
            case 3:
                int num_for_get_money;
                cout << "请输入你要取多少钱：";
                cin >> num_for_get_money;
                get_money(&name, money, num_for_get_money);
                break;
            default:
                cout << "程序退出！" << endl;
                is_run = false;
        }
    }

    delete money;

    return 0;
}  