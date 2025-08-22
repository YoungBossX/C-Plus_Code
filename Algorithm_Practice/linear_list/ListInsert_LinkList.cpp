/* 初始条件：顺序线性表L已存在，1<=1<=Listhength() */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */

typedef struct Node {
    Elemtype data;
    struct Node* next;
} Node;
typedef struct Node* LinkList;

Status ListInsert(LinkList* L, int i, ElemType e) {
    int j;
    LinkList p, s;

    p = *L;
    j = 1;

    while(p && j < i) {
        p = p -> next;
        j++;
    }

    if(!p || j > i) {
        return ERROR;
    }

    s = (LinkList)malloc(sizeof(Node));
    s -> data = e;

    s -> next = p -> next;
    p -> next = s;
    
    return OK;
}