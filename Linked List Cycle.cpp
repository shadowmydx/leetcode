class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *first  = head;
        ListNode *second = head;
        while (second)
        {
            if (first)
               first = first->next;
            else return false;
            if (first == second)
                return true;
            if (first)
                first = first->next;
            else return false;
            if (first == second)
                return true;
            second = second->next;
        }
        return false;
    }
};