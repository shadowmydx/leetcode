class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        stack<ListNode *> num1;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *head = l1;
        while (head)
        {
            num1.push(head);
            head = head->next;
        }
        
        head = plusNum(num1,l2);
        head = reverseList(head);
        return head;
    }
    
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return NULL;
        ListNode *h = NULL;
        ListNode *t = head;
        ListNode *e = t->next;
        while (e)
        {
            t->next = h;
            h = t;
            t = e;
            e = t->next;
        }
        t->next = h;
        return t;
    }
    
    ListNode *plusNum(stack<ListNode *> &num1,ListNode *l2)
    {
        int carry = 0;
        l2 = plusL2(num1,l2,carry);

        while (!num1.empty())
        {
            ListNode *tmp = num1.top();
            if (carry)
            {
                int total = tmp->val + carry;
                tmp->val  = total % 10;
                carry     = total / 10;
            }
            tmp->next = l2;
            l2 = tmp;
            num1.pop();
        }
        if (carry != 0)
        {
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->next = l2;
            tmp->val  = 1;
            l2        = tmp;
        }        
        return l2;
    }
    ListNode *plusL2(stack<ListNode *> &num1,ListNode *l2,int &carry)
    {
        if (l2 == NULL)
            return NULL;
        ListNode *nxt = plusL2(num1,l2->next,carry);
        l2->next = nxt;
        if (num1.empty())
        {
            if (carry != 0)
            {
                int total = l2->val + carry;
                l2->val   = total % 10;
                carry     = total / 10;
            }
        }
        else
        {
            int tmp = num1.top()->val;
            int total = l2->val + carry + tmp;
            l2->val = total % 10;
            carry   = total / 10;
            num1.pop();
        }
        return l2;
    }
};