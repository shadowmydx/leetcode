class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        0.注意：dp[表达式]的声明方式，不能用 = {0}的方式初始化。
        1.dp[i]的定义：s[i]开头的最长有效括号子串长度。
        2.总共有4种情况：
          0.当s[i] == ')'时，dp[i] = 0;
          1.当s[i] == '('时，有：
            3.若s[i+1] == ')',则dp[i] = 2 + dp[i+2]。这里要和后面的有效括号对连接。
            4.若s[i+1] == '(',(dp[i+1] != 0的情况已经被考虑,若dp[i+1] == 0,则s[i+1+dp[i+1]] == s[i] != ')')且s[i + 1 + dp[i+1]] == ')'               ,那么s[i]和后面的括号构成新的最长括号子串,dp[i] = dp[i + 1] + 2 + dp[i + 2 + dp[i + 1]].
        */
        int len = s.length();
        int dp[len];
        for (int i = 0;i < len;i++)
            dp[i] = 0;
        for (int i = len - 1;i >= 0;i--)
        {
            if (s[i] == ')')
                dp[i] = 0;
            else
            {
                if (i < len - 1)
                {
                    if (s[i + 1] == ')')
                        dp[i] = i + 2 < len ? 2 + dp[i + 2] : 2;
                    else if (s[i + 1] == '(')
                    {
                        if (dp[i + 1] != 0 && i + 1 + dp[i + 1] < len && s[i + 1 + dp[i + 1]] == ')')
                            dp[i] = i + 2 + dp[i + 1] >= len ? dp[i + 1] + 2 : dp[i + 1] + 2 + dp[i + 2 + dp[i + 1]];
                        else
                            dp[i] = 0;
                    }
                }
                else
                    dp[i] = 0;
            }
        }
        int max = 0;
        for (int i = 0;i < len;i++)
        {
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};