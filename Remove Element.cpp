class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        queue<int> myqueue;
        int fin = n - 1;
        for (int i = n - 1;i >= 0;i --)
        {
            if (A[i] == elem)
            {
                if (!myqueue.empty()) 
                {
                    int num = myqueue.front();
                    myqueue.pop();
                    swap(&A[i],&A[num]);
                }
                else
                {
                    fin --;
                    continue;
                }
                fin --;
            }
            myqueue.push(i);
        }
        return fin + 1;
    }
    void swap(int *a,int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};