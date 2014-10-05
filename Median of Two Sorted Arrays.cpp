class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) & 1)
            return findKth(A,m,B,n,(m+n)/2 + 1);
        else
            return (findKth(A,m,B,n,(m+n)/2) + findKth(A,m,B,n,(m+n)/2+1)) / 2.0;
    }
    double findKth(int A[],int m,int B[],int n,int k)
    {
        //always assume that m is equal or smaller than n  
        if (m > n)  
            return findKth(B, n, A, m, k);  
        if (m <= 0)
            return B[k-1];
        if (k == 1)
            return min(A[0],B[0]);
        int mida = min(k / 2,m);
        int midb = k - mida;
        if (A[mida-1] == B[midb-1])
            return A[mida-1];
        else if (A[mida-1] < B[midb-1])
            return findKth(A + mida, m - mida,B,n,k - mida);
        else
            return findKth(A,m,B + midb,n - midb,k - midb);
    }
    int min(int x,int y)
    {
        return x > y ? y : x;
    }
};