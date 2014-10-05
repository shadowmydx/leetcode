class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp)
        {
            len ++;
            tmp = tmp->next;
        }
        if (len <= 1)
            return head;
        int p = k % len;
        if (p == 0)
            return head;
        p = len - p;
        len = 0;
        tmp = head;
        ListNode *pre = NULL;
        while (len != p)
        {
            pre = tmp;
            tmp = tmp->next;
            len ++;
        }
        ListNode *nhead = tmp;
        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = head;
        head = nhead;
        pre->next = NULL;
        return head;
    }
};