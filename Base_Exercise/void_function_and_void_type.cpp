#include "iostream"

using namespace std;

void say_hello(string name) {
    cout << "Hello，" << name << "!" << endl;
}

void say_xcc (int i) {
    for (int j = 0; j < i; j++) {
        cout << "XCC" << endl;
    }
}

int main() {
    say_hello("XCC");
    say_hello("xcc");
    say_xcc(5);

    return 0;
} 