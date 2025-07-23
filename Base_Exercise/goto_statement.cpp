#include "iostream"

using namespace std;

/*
 * label A:
 * ...
 * ...
 * label B:
 * ...
 * ...
 * 
 * goto A|B|C;
 * 
 * label C:
 * ...
 * ...
 */

int main() {
    a:
    cout << "a" << endl;

    b:
    cout << "b" << endl;

    // goto a;
    goto c;

    c:
    cout << "c" << endl;

    d:
    cout << "d" << endl;

    int i = 1;
    loop:
    cout << "i = " << i << endl;
    i++;
    if (i <= 10) {
        goto loop;
    }

    return 0;
} 