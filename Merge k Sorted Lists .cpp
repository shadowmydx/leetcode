class Solution {

    class MergeHeap
    {
        public:
            MergeHeap()
            {
                heap.push_back(NULL);
            }
            bool isEmpty()
            {
                return heap.size() <= 1; // 0号元素永远为NULL
            }
            void insert(ListNode *tmp)
            {
                if (tmp == NULL)
                    return;
                heap.push_back(tmp);
                mergeInsert();
            }
            ListNode *pop()
            {
                if (this->isEmpty())
                    return NULL;
                int last = heap.size() - 1;
                ListNode *tmp = heap[1];
                heap[1] = heap[last];
                heap.pop_back();
                if (!this->isEmpty())
                    mergeDelete(1);
                return tmp;
            }
            void showHeap()
            {
                if (this->isEmpty())
                    return;
                for (int i = 1;i < heap.size();i++)
                    cout << heap[i]->val << " ";
                cout << endl;
            }
        private:
            vector<ListNode *> heap;
            void mergeDelete(int start)
            {
                int last  = heap.size() - 1;
                ListNode *tmp = heap[start];    
                int lchild = start * 2;
                int rchild = start * 2 + 1;
                int target = 0; // marked win sub-tree
                if (lchild <= last && rchild <= last)
                {
                    target = heap[rchild]->val > heap[lchild]->val ? lchild : rchild;

                }
                else if (lchild <= last)
                {
                    target = lchild;
                }
                else if (rchild <= last)
                    target = rchild;
                if (target)
                {
                    if (heap[target]->val < heap[start]->val)
                    {
                        heap[start]  = heap[target];
                        heap[target] = tmp;
                        mergeDelete(target);
                    }                    
                }
                
            }
            void mergeInsert()
            {
                int last = heap.size() - 1;
                int pare = last / 2; 
                while (pare != 0)
                {
                    if (heap[pare]->val > heap[last]->val)
                    {
                        ListNode *tmp = heap[pare];
                        heap[pare] = heap[last];
                        heap[last] = tmp;
                    }
                    else
                        break;
                    last = pare;
                    pare /= 2;
                }
            }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        MergeHeap myheap;
        int len = lists.size();
        if (!len)
            return NULL;
        for (int i = 0;i < len;i++)
            myheap.insert(lists[i]);
        ListNode *head = NULL;
        ListNode *tmp  = NULL;
        ListNode *tail = NULL;
        while (!myheap.isEmpty())
        {
            tmp = myheap.pop();
            if (!head) // init output list.
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tmp;
            }
            if (tmp->next)
            {
                myheap.insert(tmp->next);
            }
            //myheap.showHeap();
        }
        return head;
    }
};