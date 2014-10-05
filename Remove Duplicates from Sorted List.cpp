class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        ListNode *root = head;
        int num = root->val;
        while (root->next)
        {
            if (num == root->next->val)
            {
               root->next = root->next->next;
            }
            else
            {
                root = root->next;
                num = root->val;
            }
        }
        return head;
    }
};