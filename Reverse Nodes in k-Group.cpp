class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL)
            return NULL;
        int i = 0;
        ListNode *fin = head;
        while (fin != NULL && i < k - 1) // fin指向第k个结点
        {
            fin = fin->next;
            i ++;
        }
        if (fin == NULL)
            return head;
        ListNode *tail = reverseKGroup(fin->next,k);
        ListNode *tmp  = reverseList(head,fin->next); // 不能更改head。此时head指向最后一个元素，需要保留来连接tail
        head->next = tail;
        return tmp;
    }
    
    ListNode *reverseList(ListNode *head,ListNode *fin) // fin相当于end()的返回值，结尾的下一个元素
    {
        if (head == NULL)
            return NULL;
        ListNode *p = NULL;
        ListNode *t = head;
        ListNode *e = head->next;
        while (e != fin)
        {
            t->next = p;
            p = t;
            t = e;
            e = e->next;
        }
        t->next = p;
        return t;
    }
};