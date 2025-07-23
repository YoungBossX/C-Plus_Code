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

int main(){
    string names[] = {
        "Landon","Avery","Kamden","Bentley","Finnegan","Nash","Emmett","Greyson","Noah","Jace",
        "Jaxton","Sawyer","Zachary","Eli","Keegan","Lincoln","Isaac","Asher","Declan","Theo",
        "Levi","Dominic","Austin","Wyatt","Carter","Logan","Luke","Max","Ethan","Miles",
        "Oliver","Hudson","Owen","William","Joshua","Benjamin","Henry","Lucas","Alexander","Jackson",
        "Mason","Grayson","Ryder","Elijah","Liam","Caleb","Thomas","Cooper","Hunter","Connor"
    };   

    // 2x2x5三维数组
    string arr[2][2][5];

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
            for (int k = 0; k < sizeof(arr[0][0]) / sizeof(arr[0][0][0]); k++) {
                string major = i==0?"物理":"计算机";
                string class_name = j==0?"一班":"二班";
                int seat_number = k + 1;
                string name = names[get_random_number(0, sizeof(names) / sizeof(names[0]) - 1)];

                string msg = major + "专业，" + class_name + "，座位号为 " + to_string(seat_number) + " 的同学叫" + name; 

                arr[i][j][k] = msg;
            }
        }
    }

    cout << "信息准备完成，现在开始输出：" << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        for (int j = 0; j < sizeof(arr[0]) / sizeof(arr[0][0]); j++) {
            for (int k = 0; k < sizeof(arr[0][0]) / sizeof(arr[0][0][0]); k++) {
                cout << arr[i][j][k] << endl;
            }
        }
    }

    return 0;
}