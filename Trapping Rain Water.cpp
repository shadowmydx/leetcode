class Solution {
public:
    int trap(int A[], int n) {
        /*
        方法：
        0、维护一个首指针和一个尾指针，并移动小的那个，因为小的那个必将碰到比他大的墙壁。
        1、由于肯定会碰到一个大于他的墙壁，期间计算每个墙壁的差值并相加
        3、当首尾相碰时返回结果。
        */
        int left = 0,right = n - 1;
        int res = 0;
        while (A[left] == 0)
            left ++;
        while (A[right] == 0)
            right --;
        while (left < right)
        {
            if (A[left] <= A[right])
            {
                int start = A[left++];
                int count = 0;
                while (A[left] < start)
                {
                    count += start - A[left];
                    left ++;
                }
                res += count;
            }
            else
            {
                int start = A[right--];
                int count = 0;
                while (A[right] < start)
                {
                    count += start - A[right];
                    right --;
                }
                res += count;
            }
        }
        return res;
    }
};