/* 初始条件：顺序线性表L已存在，1<=1<=Listhength() */
/* 操作结果：增加L的第i个位置增加一个元素e */
/* 最好的情况：插入和删除操作刚好要求在最后一个位置操作，因为不需要移动任何元素，所以此时的时间复杂度为0(1) */
/* 最坏的情况：如果要插入和删除的位置是第一个元素那就意味着要移动所有的元素向后或者向前，所以这个时间复杂度为0(n) */

status ListInsert(SqList *L, int i, ElemType e) {
    int k;

    if(L -> length == MAXSIZE) {
        return ERROR;
    } else if(i < 1 || i -> length +１) {
        return ERROR;
    } else if(i <= L -> length) {
        for(k = length - 1; k >= i-1; k--) {
            L -> data[k + 1] = L -> data[k];
        }
    }
    L -> data[i - 1] = e;
    L -> length++;

    return OK;
}