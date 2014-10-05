class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2)
        {
            return l1 == NULL ? l2 : l1;
        }
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        head->next = NULL;
        ListNode *tmp = head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        if (l1)
        {
            tmp->next = l1;
        }
        else if (l2)
            tmp->next = l2;
        return head->next;
    }
};