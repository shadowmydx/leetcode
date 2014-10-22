/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        unordered_map<int,int> dict;
        RandomListNode *tmpHead = head;
        RandomListNode *resHead = NULL;
        RandomListNode *now     = NULL;
        RandomListNode *nxt     = NULL;
        resHead = (RandomListNode *)malloc(sizeof(RandomListNode));
        dict[(int)head] = (int)resHead;
        resHead->label = tmpHead->label;
        resHead->next  = NULL;
        resHead->random = NULL;
        now  = resHead;        
        tmpHead = tmpHead->next;
        while (tmpHead)
        {
            nxt = (RandomListNode *)malloc(sizeof(RandomListNode));
            nxt->label = tmpHead->label;
            nxt->next  = NULL;
            nxt->random = NULL;
            dict[(int)tmpHead] = (int)nxt;
            now->next = nxt;
            now = nxt;
            tmpHead = tmpHead->next;
        }
        tmpHead = head;
        while (tmpHead)
        {
            now = (RandomListNode *)dict[(int)tmpHead];
            if (tmpHead->random != NULL)
                now->random = (RandomListNode *)dict[(int)(tmpHead->random)];

            tmpHead = tmpHead->next;
        }
        return resHead;
    }
};