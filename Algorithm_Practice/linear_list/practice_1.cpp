#include <iostream>
#include <ctime>

using namespace std;

#define ElemType int

struct Node {
    ElemType data;
    Node* next;
    Node(ElemType d = 0, Node* n = nullptr) : data(d), next(n) {}
};

Node* buildByTailInsert(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        Node* s = new Node(rand() % 100, nullptr);
        if (!head) head = tail = s;
        else { tail->next = s; tail = s; }
    }
    return head;
}

Node* buildByHeadInsert(int n) {
    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        head = new Node(rand() % 100, head);
    }
    return head;
}

void printList(Node* L) {
    int idx = 1;
    for (Node* p = L; p; p = p->next, ++idx) {
        cout << idx << "--" << p->data << (p->next ? " -> " : "\n");
    }
}

bool getMidNode(Node* L, ElemType& e) {
    if (!L) return false;
    Node* fast = L;
    Node* slow = L;
    while (fast->next != nullptr) {
        if (fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        } else {
            fast = fast->next;
        }
    }
    e = slow -> data; 
    return true;
}

void destroyList(Node* L) {
    while (L) { 
        Node* t = L -> next; 
        delete L; 
        L = t; 
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Node* L = buildByTailInsert(20);

    cout << "随机生成的链表（20 个元素）:\n";
    printList(L);

    ElemType midVal;

    if (getMidNode(L, midVal)) {
        cout << "中间结点的值：" << midVal << endl;
        cout << "（偶数长度时取前一个中点）" << endl;
    } else {
        cout << "链表为空，无法获取中间结点。\n";
    }
    
    destroyList(L);
    return 0;
}