class Solution {
public:
    void sortColors(int A[], int n) {
        int start = swapZero(A,n);
        int sptr = start + 1,fptr = n - 1;
        while (sptr < fptr)
        {
            while (sptr < n && A[sptr] == 1)
                sptr ++;
            while (fptr < n && A[fptr] == 2)
                fptr --;
            if (fptr < n && sptr < fptr)
                swap(&A[fptr],&A[sptr]);
        }
    }
    int swapZero(int A[],int n)
    {
        int j = 0;
        for (int i = 0;i < n;i++)
        {
            if (A[i] == 0)
            {
                swap(&A[j],&A[i]);
                j++;
            }
        }
        return j - 1;
    }
    void swap(int *a,int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};