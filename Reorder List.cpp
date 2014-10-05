class Solution {
public:
    /*
    0、首先获得链表的全部长度
    1、将后半链表全部入栈，并断开前后的联系。
    2、将栈中元素插入前半链表的间隙。
    */
    void reorderList(ListNode *head) {
        ListNode *tail = head;
        ListNode *pre  = head;
        ListNode *sec  = head;
        stack<ListNode *> mystk;
        if (!head)
            return;
        int len = 0;
        while (tail)
        {
            len ++;
            tail = tail->next;
        }
        tail = head;
        if (len % 2 != 0)
            len = len / 2 + 1;
        else
            len /= 2;
        int i = 0;
        while (i != len)
        {
            pre  = tail;
            tail = tail->next;
            i ++;
        }
        pre->next = NULL;
        if (!tail)
            return;
        pre = head;
        while (tail)
        {
            mystk.push(tail);
            tail = tail->next;
        }
        while (!mystk.empty())
        {
            tail = mystk.top();
            sec = pre->next;
            pre->next = tail;
            tail->next = sec;
            pre = sec;
            mystk.pop();
        }
        return;
    }
};