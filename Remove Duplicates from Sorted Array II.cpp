class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        int i = 0;
        int count = 0;
        int pre = 1 << 31;
        while (j < n)
        {
            A[i] = A[j];
            if (j + 1 < n && j + 2 < n && A[j] == A[j+1] && A[j] == A[j+2])
            {
                A[i++] = A[j++];
                A[i] = A[j];
                while (j < n - 1 && A[j] == A[j+1])
                    j++;
            }
            i++,j++;
        }
        return n == 0 ? 0 : i;
    }

};