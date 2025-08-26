#include <iostream>

using namespace std;

class CircularList {
public:
    CircularList() : size(0) {
        head = new Node(-1);
        head -> next = head; 
    }

    ~CircularList() {
        clear();
        delete head;
        head = nullptr;
    }

    void clear() {
        Node* cur = head->next;
        while (cur != head) {
            Node* t = cur -> next;
            delete cur;
            cur = t;
        }
        head -> next = head;
        size = 0;
    }

    int length() {
        return size;
    }

    int getValue(int pos) {
        if (pos < 1 || pos > size) {
            return -1;
        }
        Node* cur = head -> next;
        for (int i = 1; i < pos; ++i) {
            cur = cur -> next;
        }
        return cur->data;
    }

    void pushBack(int val) {
        insertNode(size + 1, val);
    }

    bool insertNode(int pos, int val) {
        if (pos < 1 || pos > size + 1) {
            return false;
        }
        Node* prev = getPreIndex(pos);
        Node* node = new Node(val, prev -> next);
        prev -> next = node;
        size++;
        return true;
    }

    bool deleteNode(int val) {
        Node* pre = findPreValue(val);
        if (!pre) {
            return false;
        }
        Node* node = pre->next;
        pre -> next = node -> next;
        delete node;
        size--;
        return true;
    }

    int locateValue(int val) {
        int idx = 1;
        Node* cur = head -> next;
        while (cur != head) {
            if (cur -> data == val) return idx;
            cur = cur -> next;
            ++idx;
        }
        return 0;
    }

    void traverse() {
        Node* cur = head -> next;
        if (cur == head) {
            cout << "链表为空" << endl;
            return;
        }
        while (cur != head) {
            cout << cur -> data << " ";
            cur = cur -> next;
        }
    }

private:
    struct Node {
        int data;
        Node* next;
        Node() : data(0), next(nullptr) {}
        Node(int val) : data(val), next(nullptr) {}
        Node(int val, Node* next) : data(val), next(next) {}
    };

    Node* head;
    int size;

    Node* getPreIndex(int pos) {
        Node* prev = head;
        for (int i = 1; i < pos; ++i) {
            prev = prev -> next;
        }
        return prev;
    }

    Node* findPreValue(int val) {
        Node* pre = head;
        Node* cur = head -> next;
        while(cur != head) {
            if (cur -> data == val) {
                return pre;
            }
            pre = cur;
            cur = cur -> next;
        }
        return nullptr;
    }
};

void showMenu() {
    cout << "1. 初始化链表" << endl;
    cout << "2. 插入结点" << endl;
    cout << "3. 删除结点" << endl;
    cout << "4. 返回结点位置" << endl;
    cout << "5. 遍历链表" << endl;
    cout << "0. 退出" << endl;
    cout << "请选择你的操作：";
}

bool readInt(const char* prompt, int& out) {
    cout << prompt << endl;
    if (cin >> out) return true;
    cin.clear();
    cin.ignore();
    cout << "输入非法，请重新选择！" << endl;
    return false;
}

int main() {
    CircularList list;

    int op = -1;

    while(true) {
        showMenu();

        if(!(cin >> op)) {
            cin.clear();
            cin.ignore();
            cout << "输入非法，请重新选择!" << endl;
            continue;
        }

        if (op == 0) {
            cout << "已退出，感谢使用!" << endl;
            break;
        }

        switch (op) {
            case 1: {
                list.clear();
                cout << "输入结点的值，输入 (-1) 完成初始化：" << endl;
                while (true) {
                    int val; 
                    if (!(cin >> val)) {
                        cin.clear();
                        cin.ignore();
                        cout << "输入非法，停止初始化！" << endl;
                        break;
                    }
                    if (val == -1) {
                        break;
                    }
                    list.pushBack(val);
                }

                cout << "链表中节点的值：";
                for (int i = 1; i <= list.length(); ++i) {
                    cout << list.getValue(i) << " ";
                }

                cout << "初始化完成，共 " << list.length() << " 个结点。" << endl;
                break;
            }
            case 2: {
                int insert_pos, insert_val;
                if(!readInt("请输入插入位置：", insert_pos)) break;
                if(!readInt("请输入插入值：", insert_val)) break;
                if (list.insertNode(insert_pos, insert_val)) {
                    cout << "插入成功！" << endl;
                } else {
                    cout << "插入失败！" << endl;
                }
                break;
            }
            case 3: {
                int delete_val;
                if(!readInt("请输入删除值：", delete_val)) break;
                if (list.deleteNode(delete_val)) {
                    cout << "删除成功！" << endl;
                } else {
                    cout << "删除失败！" << endl;

                }
                break;
            }
            case 4: {
                int location_val;
                if (!readInt("请输入要查找的结点值：", location_val)) break;
                int pos = list.locateValue(location_val);
                if (pos == 0) cout << "未找到该值。" << endl;
                else cout << "该结点首次出现的位置为：" << pos << endl;
                break;
            }
            case 5: {
                cout << "当前链表：";
                list.traverse();
                break;
            }
            default: {
                cout << "输入有误，请重新输入！" << endl;
                break;
            }
        }
    } 

    return 0;
}