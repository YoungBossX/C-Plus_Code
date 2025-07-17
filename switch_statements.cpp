#include "iostream"

using namespace std;

int main() {
    // 输入数字1-7，输出星期几
    // char num;
    // cout << "请输入字符数字（1-7）代表今天星期几：";
    // cin >> num;

    // switch (num)
    // {
    // case '1':
    //     cout << "今天是星期一" << endl;
    //     break;
    // case '2':
    //     cout << "今天是星期二" << endl;
    //     break;
    // case '3':
    //     cout << "今天是星期三" << endl;
    //     break;
    // case '4':
    //     cout << "今天是星期四" << endl;
    //     break;
    // case '5':
    //     cout << "今天是星期五" << endl;
    //     break;
    // case '6':
    //     cout << "今天是星期六" << endl;
    //     break;
    // case '7':
    //     cout << "今天是星期日" << endl;
    //     break;
    // default:
    //     cout << "输入错误，请输入1-7之间的数字！" << endl;
    // }

    // 请给电影打分10和9是优秀、8和7是一搬、6和5是普通、低于5是垃圾
    // int num;
    // cout << "请输入电影评分（0-10）：";
    // cin >> num;

    // switch (num) {
    //     case 10:
    //     case 9:
    //         cout << "优秀" << endl;
    //         break;
    //     case 8:
    //     case 7:
    //         cout << "一般" << endl;
    //         break;
    //     case 6:
    //     case 5:
    //         cout << "普通" << endl;
    //         break;
    //     default:
    //         if (num < 5 && num >= 0) {
    //             cout << "垃圾" << endl;
    //         } else {
    //             cout << "输入错误，请输入0-10之间的数字！" << endl;
    //         }
    // }

    // 假设当前正在准备直播的场景。通过键盘输入数字，来决定场景。
    cout << "请选择直播的场景，输入对应的场景代码数字。" << endl;
    cout << "1: 仅输出屏幕，2: 输出屏幕+摄像头画面，3: 仅输出摄像头画面：";

    int num;
    cin >> num;

    switch (num) {
        case 1:
            cout << "已经切换为场景1，用户只能看到屏幕画面。" << endl;
            break;
        case 2:
            cout << "已经切换为场景2，用户可以看到屏幕和摄像头画面。" << endl;
            break;
        case 3:
            cout << "已经切换为场景3，用户仅可看到摄像头画面。" << endl;
            break;
        default:
            cout << "您输入的代码有误，无法识别具体场景。" << endl;
    }

    return 0;
}