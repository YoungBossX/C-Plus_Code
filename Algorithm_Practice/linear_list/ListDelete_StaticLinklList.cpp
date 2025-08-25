/* 删除在 L 中的第 i 个数据元素 
 * 优点：
 *  - 在插入和删除操作时，只需要修改游标，不需要移动元素，从而改进了在顺序存储结构中的插入和删除操作需要移动大量元素的缺点
 * 缺点：
 *  - 没有解决连续存储分配(数组)带来的表长难以确定的问题
 *  - 失去了顺序存储结构随机存取的特性
 */

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

Status ListDelete(StaticLinkList L, int i)
{
    int j, k;

    if (i < 1 || i > ListLength(L))
    {
        return ERROR;
    }

    k = MAX_SIZE - 1;

    for (j = 1; j <= i - 1; j++)
    {
        k = L[k].cur;
    }

    j = L[k].cur;
    L[k].cur = L[j].cur;

    Free_SLL(L, j);

    return OK;
}

/* 将下标为 k 的空闲结点回收到备用链表 */
void Free_SLL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

/* 返回 L 中数据元素个数 */
int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;

    while (i)
    {
        i = L[i].cur;
        j++;
    }

    return j;
}