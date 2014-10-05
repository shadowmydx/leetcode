class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0;i < n;i++)
        {
            if (A[i] > 0 && A[i] < n)
            {
                int tmp = A[i] - 1;
                if (A[i] != A[tmp]) {
                    swap(&A[tmp],&A[i]);
                    i --;
                }
            }
        }
        for (int i = 0;i < n;i++)
            if (A[i] != i + 1)
                return i + 1;
        if (n > 1)return A[n-1] + 1;
        if (n == 1)
        {
            if (A[0] == 1)
                return 2;
            return 1;
        }
        return 1;
    }
    void swap(int *a,int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};