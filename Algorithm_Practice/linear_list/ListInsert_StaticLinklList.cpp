/* 在静态链表工中第i个元素之前插入新的数据元素e */

#define MAXSIZE 1000

typedef struct
{
    ElemType data;    // 数据
    int cur;          // 游标 (Cursor)
} Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space) {
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
    
    space[MAXSIZE - 1].cur = 0;

    return OK;
}

// 获得空闲分量的下标
int Malloc_SLL() {
    int i = space[0].cur;

    if (space[0].cur)
        space[0].cur = space[i].cur; 

    return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e) {
    int i, j, k;

    k = MAXSIZE - 1;
    if(i < 1 || i > ListLength(L) + 1) {
        return ERROR;
    }

    j = Malloc_SLL(L);

    if(j) {
        L[j].data = e;
        for(int l = 1; l <= i - 1; l++) {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;

        return OK;
    }

    return ERROR;
}