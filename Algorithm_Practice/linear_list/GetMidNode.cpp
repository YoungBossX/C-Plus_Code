/* 利用快慢指针原理:设置两个指针*search、*mid都指向单链表的头节点。其中*search的移动速度是*mid的2倍。当*search指向末尾节点的时候，mid正好就在中间了。这也是标尺的思想。 */

Status GetMidNode(LinkList L, ElemType *e)
{
    LinkList search, mid;
    mid = search = L;

    while (search->next != NULL)
    {
        // search 移动的速度是 mid 的 2 倍
        if (search->next->next != NULL)
        {
            search = search->next->next;
            mid = mid->next;
        }
        else
        {
            search = search->next;
        }
    }

    *e = mid->data;

    return OK;
}
