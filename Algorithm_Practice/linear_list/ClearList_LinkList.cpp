typedef struct Node {
    Elemtype data;
    struct Node* next;
} Node;
typedef struct Node* LinkList;

Status ClearList(LinkList* L) {
    p = (*L) -> next;

    while(p) {
        q = p -> next;
        free(p);
        p = q;
    }

    (*L) -> next = NULL;

    return OK;
}