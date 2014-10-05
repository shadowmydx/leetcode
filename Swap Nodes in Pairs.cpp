class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return NULL;
        ListNode *tmp;
        ListNode *bak;
        if (head->next)
            tmp = swapPairs(head->next->next);
        else 
            return head;
        bak = head->next;
        head->next = tmp;
        bak ->next = head;
        head       = bak;
        return head;
    }
};