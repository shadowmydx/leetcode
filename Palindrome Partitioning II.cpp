class Solution {
public:
    /*
     * 方法：
     * 0、预处理字符串，用动态规划的方法实现标示出起点i、终点j是否能构成回文子串。
     * 1、根据0步的成果，定义DP[i]为：从i点开始分割的最小值，则有：DP[i] = 0 ,min(DP[k+1] + 1) 其中，当终点和i构成回文时为0
     */
    char dp[1501][1501]; // 标记起点为i、终点为j的子字符串是否构成回文串。注意：用int会爆
    int minCut(string s) {
        int len = s.size();
        int DP[len]; // 以i开头的字符串的最小切割方案。

        for (int i = 0;i < len;i++)
        {
            dp[i][i] = 1;
            for (int j = len - 1;j > i;j--)
            {
                dp[i][j] = findPa(i,j,s);
            }
        }
        int min = (1 << 30);
        for (int i = len - 1;i >= 0;i--) // 轮到谁开头了？
        {
            for (int j = i;j < len;j++) //  穷举一个结尾。
            {
                if (dp[i][j] == 1)
                {
                    if (j == len - 1)
                        min = 0;
                    else
                    {
                        if (min > DP[j+1] + 1)
                            min = DP[j+1] + 1;
                    }
                }
            }
            DP[i] = min;
            min   = (1 << 30);
        }
        return DP[0];
    }
    
    char findPa(int start,int fin,string &s)
    {
        if (dp[start][fin] != 0)
            return dp[start][fin];
        if (start >= fin)
            return 1;
        if (s[start] == s[fin])
            return dp[start][fin] = findPa(start + 1,fin - 1,s);
        else
            return dp[start][fin] = -1;
    }
    
};