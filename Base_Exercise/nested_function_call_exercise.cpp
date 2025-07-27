#include "iostream"

using namespace std;

int get_min(int a, int b) {
    return (a < b) ? a : b;
}

int get_max(int a, int b) {
    return (a > b) ? a : b;
}

struct MinAndMax {
    int min;
    int max;
};

struct MinAndMax get_min_and_max(int a, int b) {
    struct MinAndMax result;
    result.min = get_min(a, b);
    result.max = get_max(a, b);
    return result;
}

int main() {
    struct MinAndMax result = get_min_and_max(10, 20);
    cout << "最小值：" << result.min << endl;
    cout << "最大值：" << result.max << endl;

    return 0;
}   