#include "iostream"

using namespace std;

int* get_max_static(int arr[], int length) {
    if (length <= 0) {
        return nullptr; 
    }

    static int max_value; 

    for (int i = 0; i < length; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i]; 
        }
    }

    return &max_value;
}

int* get_max_dynamic(int arr[], int length) {
    if (length <= 0) {
        return nullptr; 
    }

    int* max_value = new int;

    for (int i = 0; i < length; i++) {
        if (arr[i] > *max_value) {
            *max_value = arr[i]; 
        }
    }

    return max_value;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 70, 8, 9, 10};
    int* static_max = get_max_static(arr, sizeof(arr) / sizeof(arr[0]));
    int* dynamic_max = get_max_dynamic(arr, sizeof(arr) / sizeof(arr[0]));

    cout << "Static max: " << *static_max << endl;
    cout << "Dynamic max: " << *dynamic_max << endl;

    delete dynamic_max;

    return 0;
}  