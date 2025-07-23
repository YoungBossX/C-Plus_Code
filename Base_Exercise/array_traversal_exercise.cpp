#include "iostream"
#include <random>

using namespace std;

int get_random_number(int min, int max) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(min, max);  

    int random_number = dis(gen);
    return random_number;
}

int main(){
    // 生成10个随机数，存入数组
    int arr[10];
    cout << "生成的数组元素：";
    for (int i = 0; i < 10; ++i) {
        arr[i] = get_random_number(1, 100);
        cout << arr[i] << " ";
    }
    cout << endl;

    // 查找最大值和最小值
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < 10; ++i) {
        if (arr[i] > max_val) max_val = arr[i];
        if (arr[i] < min_val) min_val = arr[i];
    }

    cout << "最大值：" << max_val << endl;
    cout << "最小值：" << min_val << endl;

    return 0;
}