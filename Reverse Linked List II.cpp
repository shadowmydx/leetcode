class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)return head;
        ListNode *root = head;
        ListNode *start = NULL;
        ListNode *pre = NULL;
        ListNode *fin;
        ListNode *finN;
        ListNode *r,*y,*t;
        int i = 1;
        while (i != m)
        {
            pre = root;
            root = root->next;
            i++;
        }
        start = root;
        r = NULL,y = root;
        while (i != n + 1)
        {
            t = y->next;
            y->next = r;
            r = y;
            y = t;
            i++;
        }
        if (start)
            start->next = y;        
        if (m == 1)
            return r;
        if (pre)
            pre->next = r;


        return head;
    }

};