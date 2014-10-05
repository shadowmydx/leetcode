class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fi = head;
        ListNode *se = head;
        ListNode *th = head;
        int flag = 0;
        if (!head)
            return NULL;
        while (fi)
        {
            if (fi)
                fi = fi->next;
            if (fi == se)
            {
                flag = 1;
                break;
            }
            if (fi)
                fi = fi->next;
            se = se->next;
        }
        if (!flag)
            return NULL;
        int fsum = 0;
        int ssum = 0;
        while (!ssum || fi != se)
        {
            fi = fi->next;
            fsum ++;
            if (fi == se)
                break;
            fi = fi->next;
            se = se->next;
            ssum ++;
            fsum ++;
        }
        fsum -= ssum;
        int res = 0;
        while (th != se)
        {
            th = th->next;
            res ++;
        }
        int min = res;
        int mak = res;
        res = 0;
        while (res != mak)
        {
            res = 0;
            se = se->next;
            th = head;
            while (se != th)
            {
                res ++;
                th = th->next;
            }
            if (res < min)
                min = res;
        }
        res = 0;
        th = head;
        while (res != min)
        {
            th = th->next;
            res++;
        }
        return th;
    }
};