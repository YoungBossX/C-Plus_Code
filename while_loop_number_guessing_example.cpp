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
    /*
     * 1. 无限次机会
     * 2. 提示大了或者小了
     * 3. 提示总共猜了多少次
     */
    // 1. 得到一个随机数1-100范围
    int num = get_random_number(1, 100); 
    cout << "num是: " << num << endl;

    // 2. 提示用户输入数字进行猜测
    int guess_num;
    cout << "请首次猜测一下数字：";
    cin >> guess_num;

    int count = 1;

    // 3. 判断，如果猜错继续猜测
    while (guess_num != num) {
        count++;
        cout << "不好意思，你猜错了！" << endl;

        if (guess_num < num) {
            cout << "你猜的数字小了，请重新猜测！" << endl;
            cin >> guess_num; 
        } else {
            cout << "你猜的数字大了，请重新猜测！" << endl;
            cin >> guess_num; 
        }       
    }

    cout << "恭喜你猜对了！" << endl;
    cout << "你总共猜了" << count << "次！" << endl;

    return 0;
} 