#include "iostream"

using namespace std;

/*
 * 会有多层循环嵌套
 * 每一层循环对应一个维度
 * 一般for循环更为方便
 */

int main() {
    int arr1[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        // arr1[0] = {1, 2, 3}
        // arr1[1] = {4, 5, 6}
        for (int j = 0; j < sizeof(arr1[0]) / sizeof(arr1[0][0]); j++) {
            // arr1[0][0] = 1
            // arr1[0][1] = 2
            // arr1[0][2] = 3
            // arr1[1][0] = 4
            // arr1[1][1] = 5
            // arr1[1][2] = 6
            cout << arr1[i][j] << " ";
        }
    }

    cout << endl;

    int i = 0;
    while (i < sizeof(arr1) / sizeof(arr1[0])) {
        int j = 0;
        while (j < sizeof(arr1[0]) / sizeof(arr1[0][0])) {
            cout << arr1[i][j] << " ";
            j++;
        }
        i++;
    }

    cout << endl;

    int arr2[2][2][3] = {
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        {
            {7, 8, 9},
            {10, 11, 12}
        }
    };

    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
        // arr2[0] = {{1, 2, 3}, {4, 5, 6}}
        // arr2[1] = {{7, 8, 9}, {10, 11, 12}}
        for (int j = 0; j < sizeof(arr2[0]) / sizeof(arr2[0][0]); j++) {
            // arr2[0][0] = {1, 2, 3}
            // arr2[0][1] = {4, 5, 6}
            // arr2[1][0] = {7, 8, 9}
            // arr2[1][1] = {10, 11, 12}
            for (int k = 0; k < sizeof(arr2[0][0]) / sizeof(arr2[0][0][0]); k++) {
                // arr2[0][0][0] = 1
                // arr2[0][0][1] = 2
                // arr2[0][0][2] = 3
                // arr2[0][1][0] = 4
                // arr2[0][1][1] = 5
                // arr2[0][1][2] = 6
                // arr2[1][0][0] = 7
                // arr2[1][0][1] = 8
                // arr2[1][0][2] = 9
                // arr2[1][1][0] = 10
                // arr2[1][1][1] = 11
                // arr2[1][1][2] = 12
                cout << arr2[i][j][k] << " ";
            }
        }
    }

    cout << endl;

    int x = 0;
    while (x < sizeof(arr2) / sizeof(arr2[0])) {
        int y = 0;
        while (y < sizeof(arr2[0]) / sizeof(arr2[0][0])) {
            int z = 0;
            while (z < sizeof(arr2[0][0]) / sizeof(arr2[0][0][0])) {
                cout << arr2[x][y][z] << " ";
                z++;
            }
            y++;
        }
        x++;
    }
    
    return 0;
} 