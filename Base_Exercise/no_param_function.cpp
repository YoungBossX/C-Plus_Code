#include "iostream"

using namespace std;

void say_xcc() { // ()也是需要写的
    for (int i = 0; i < 6; ++i) {
        cout << "XCC" << endl;
    }
}

int main() {
    // 调用的时候()也是需要写的
    say_xcc();

    return 0;
} 