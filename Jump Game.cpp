class Solution {
public:
    bool canJump(int A[], int n) {
        /*
        思路：由于最多可以走多少步，说明可以任选，同时只要在一个格子能走到终点，该格子就能取代终点
              成为新的终点。因此设定一个near变量标记，初始化为终点，当在A格子能走到终点时，更新终点为A，以此类推
        */
        if (n == 1)
            return true;
        int dp[n];
        int near = n - 1;
        for (int i = 0;i < n;i++)
            dp[i] = 0;
        dp[near] = 1;
        for (int i = n - 2;i >= 0;i--)
        {
            if (A[i] + i >= near)
            {
                dp[i] = 1;
                near = i;
            }
        }
        return dp[0] == 1 ? true : false;
    }
};