class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        int i = 0;
        while (j < n)
        {
            A[i] = A[j];
            while (j < n - 1 && A[j] == A[j+1])
                j++;
            i++,j++;
        }
        return n == 0 ? 0 : i;
    }
};