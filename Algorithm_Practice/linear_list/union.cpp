void unionL(List* La, list Lb) {
    int La_len, Lb_len;
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);

    for(int i = 1; i <= Lb_len; i++) {
        GetElem(Lb, i, &e);
        if(!ListFind(*La, e)) {
            ListInsert(La, ++La_len, e);
        }
    }
}