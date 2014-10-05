class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // dp[i] : 若处于递增，则值为最高点的序号。若不处于，则为i
        // 思路是从开始递增买，递增结束卖出
        int n = prices.size();
        if (n == 0)
            return 0;
        int dp[n];
        int profit = 0;
        dp[n - 1] = n - 1;
        for (int i = n - 2;i >= 0;i --)
        {
            if (prices[i] < prices[i+1])
            {
                dp[i] = dp[i+1];
            }
            else dp[i] = i;
        }
        int i = 0;
        while (i < n)
        {
            if (dp[i] != i)
            {
                profit += prices[dp[i]] - prices[i];
                i = dp[i];
            }
            else i++;
        }
        return profit;
    }
};