/* 初始条件：顺序线性表L已存在，1<=1<=Listhength() */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度-1 */
/* 最好的情况：插入和删除操作刚好要求在最后一个位置操作，因为不需要移动任何元素，所以此时的时间复杂度为0(1) */
/* 最坏的情况：如果要插入和删除的位置是第一个元素那就意味着要移动所有的元素向后或者向前，所以这个时间复杂度为0(n) */

status ListDelete(SqList *L, int i, ElemType *e) {
    int k;

    if(L -> length == 0) {
        return ERROR;
    } else if (i < 1 || i > L -> length) {
        return ERROR;
    } 

    *e = L -> datap[i - 1];

    if(i < length) {
        for (k = i - 1, k < length; ++k) {
            L -> data[k] = L -> data[k + 1];
        }
    }

    L -> length--;

    return OK;
}