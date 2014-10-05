class Solution {
public:
    int maxSubArray(int A[], int n) {
        int dp[n]; // 以n结尾的连续数列，之最大值
        dp[0] = A[0];
        for (int i = 1;i < n;i++)
        {
            if (A[i] < dp[i-1] + A[i])
                dp[i] = dp[i-1] + A[i];
            else 
                dp[i] = A[i];
        }
        int max = dp[0];
        for (int i = 1;i < n;i++)
        {
            if (max < dp[i])
                max = dp[i];
        }
        return max;
    }
};