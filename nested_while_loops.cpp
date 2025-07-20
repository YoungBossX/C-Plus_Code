#include "iostream"
#include "random"

using namespace std;

int get_random_number(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(min, max);  

    int random_number = dis(gen);
    return random_number;
}

int main() {
    /*
     * while (条件) 
     * {
     *      // 循环体
     *      ...
     *      ...
     * 
     *      while (条件)
     *     {
     *         // 内部循环体
     *        ...
     *        ...
     *     }
     * }
     */

    bool is_continue = true;

    while (is_continue) {
        cout << "C++" << endl;

        int i = 0;
        while (i < 3) {
            cout << "-" << endl;
            i++;
        } 

        int num = get_random_number(1, 20);
        if (num == 1) { // 模拟百分之五的概率
            is_continue = false;
        }
    }

    cout << "C" << endl;

    return 0;
}   