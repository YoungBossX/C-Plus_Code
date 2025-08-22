/* 头插法建立单链表示例 */

typedef struct Node {
    Elemtype data;
    struct Node* next;
} Node;
typedef struct Node* LinkList;


void CreateListHead(LinkList* L, int n) {
    LinkList p;
    int i;

    srand(time(0));

    *L = (LinkList)malloc(sizeof(Node));
    (*L) -> next = NULL;

    for(i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p -> data = rand() % 100 + 1;
        p -> next = (*L) -> next;
        (*L) -> next = p;
    }
}