/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *tar   = head;
        ListNode *pre   = head;
        ListNode *start = head;
        if (!head)
            return NULL;
        while (n != 0)
        {
            start = start->next;
            n --;
        }
        while (start)
        {
            pre   = tar;
            start = start->next;
            tar   = tar->next;
        }
        if (pre == tar)
            return pre->next;
        pre->next = tar->next;
        return head;
    }
};