class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i,j,q;
        i = j = q = 0;
        int c[m+n+1];
        while (i < m && j < n)
        {
            if (A[i] > B[j])
                c[q++] = B[j++];
            else 
                c[q++] = A[i++];
        }
        if (q < m + n)
        {
            if (i < m)
            {
                while (i < m)
                {
                    c[q++] = A[i++];
                }
            }
            else
                while (j < n)
                    c[q++] = B[j++];
        }
        for (i = 0;i < q;i++)
            A[i] = c[i];
    }
};