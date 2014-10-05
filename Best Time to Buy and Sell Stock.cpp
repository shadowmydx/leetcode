class Solution {
public:
    int maxProfit(vector<int> &prices) {
        //思路：若在某天买进，则在某天后的价值最高点卖出利润最大。所以要求某天后的价值最高点。
        int profit = 0;
        int n = prices.size();
        int dp[n]; // dp[i] : i为起点，之后的最大值的序号。
        dp[n-1] = n - 1;
        for (int i = n - 2;i >= 0;i--)
        {
            if (prices[i] > prices[dp[i+1]])
            {
                dp[i] = i;
            }
            else dp[i] = dp[i+1];
        }
        
        for (int i = 0;i < n;i++)
        {
            int num = prices[dp[i]] - prices[i];
            if (num > profit)
                profit = num;
        }
        return profit;
    }

};