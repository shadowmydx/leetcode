class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1001][1001];
        int slen = s.size();
        for (int i = 0;i < slen;i++)
            for (int j = 0;j < slen;j++)
            {
                dp[i][j] = i == j ? 1 : -1;
            }
        init(dp,0,slen - 1,s);
        int start,fin;
        int max = 0;
        for (int i = 0;i < slen;i++)
            for (int j = 0;j < slen;j++)
            {
                if (dp[i][j] == 1)
                {
                    if (j - i + 1 > max)
                    {
                        max = j - i + 1;
                        start = i;
                        fin   = j;
                    }
                }
            }
        return s.substr(start,max);
    }
    int init(int dp[][1001],int start,int fin,string &s)
    {
        if (dp[start][fin] != -1)
            return dp[start][fin];
        if (start > fin)
            return 1;
        dp[start][fin] = 0;
        if (s[start] == s[fin])
            dp[start][fin] = init(dp,start + 1,fin - 1,s);
        if (dp[start][fin] == 0)
        {
            init(dp,start + 1,fin,s);
            init(dp,start,fin - 1,s);
        }
        return dp[start][fin];
    }
};