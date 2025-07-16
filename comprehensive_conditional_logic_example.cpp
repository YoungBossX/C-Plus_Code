#include "iostream"
#include "random"

using namespace std;

/*
 * 案例需求（猜扑克牌）：
 * 随机产生3分信息 
 * 第一份信息：1-10的数字，代表扑克牌1-10
 * 第二份信息：字符串，红色或黑色，代表扑克牌的花色
 * 第三份信息：字符串，如果是红色产出红桃或方块，如果是黑色产出黑桃或梅花
 * 案例要求：
 * 通过嵌套判断，并结合判断语句猜测上述信息，如
 * 先猜数字，成功后猜颜色，再成功猜测具体的花型
 */

int get_random_number(int min, int max) {
    // 创建一个随机数生成器
    random_device rd;
    mt19937 gen(rd());

    // 创建一个均匀分布的整数分布
    uniform_int_distribution<> dis(min, max);
    
    int random_number = dis(gen);
    return random_number;
}
 
int main(){
    int num = get_random_number(1, 10);
    // cout << "随机生成数字（1-10）：" << num << endl;
    string color = get_random_number(0, 1)? "红色" : "黑色";
    string suit;

    if (color == "红色") {
        suit = get_random_number(0, 1) ? "红桃" : "方块";
    } else {
         suit = get_random_number(0, 1) ? "黑桃" : "梅花";
    }
    // cout << "随机生成的扑克牌信息：" << num << " " << color << " " << suit << endl;
    
    int guess_num;
    cout << "请输入猜测的扑克牌数字：";
    cin >> guess_num;

    if (guess_num == num) {
        cout << "数字猜测正确！" << endl;
        cout << "请输入猜测的扑克牌颜色（红色/黑色），红色输入1，黑色输入0：";
        int color_num;
        cin >> color_num;

        if ((color_num? "红色" : "黑色") == color) {
            cout << "颜色猜测正确！" << endl;
            int suit_num;

            if (color == "红色") {
                cout << "请猜测花型（红桃/方块），红桃输入1，方块输入0：";
                cin >> suit_num;

                if ((suit_num? "红桃" : "方块") == suit) {
                    cout << "花型猜测正确！恭喜你猜对了扑克牌！游戏的花型是：" << suit << endl;
                } else {
                    cout << "花型猜测错误，游戏结束！正确的花型是：" << suit << endl;
                }
            } else {
                cout << "请猜测花型（黑桃/梅花），黑桃输入1，梅花输入0：";
                cin >> suit_num;

                if ((suit_num? "黑桃" : "梅花") == suit) {
                    cout << "花型猜测正确！恭喜你猜对了扑克牌！游戏的花型是：" << suit << endl;
                } else {
                    cout << "花型猜测错误，游戏结束！正确的花型是：" << suit << endl;
                }
            }
        } else {
            cout << "颜色猜测错误，游戏结束！" << endl;
        }

    } else {
        cout << "数字错误，游戏结束！" << endl;
    }
        
    return 0;
}   