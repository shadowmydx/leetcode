class Solution {
public:
    int dp[1001][1001]; // dp[i][j]:起点为i，终点为j的substring是否为回文
    vector<vector<string> > partition(string s) {
        int len = s.size();
        for (int i = 0;i < len;i++)
        {
            dp[i][i] = 1;
            for (int j = len - 1;j > i;j--)
            {
                dp[i][j] = findPa(i,j,s);
            }
        }
        vector<string> now;
        vector<vector<string> > res;
        findResult(0,s,now,res);
        return res;
    }
    
    void findResult(int start,string &s,vector<string> &now,vector<vector<string> > &res)
    {
        int len = s.size();
        if (start >= len)
        {
            res.push_back(now);
            return;
        }
        for (int i = start;i < len;i++)
        {
            if (dp[start][i] == 1)
            {
                now.push_back(s.substr(start,i - start + 1));
                findResult(i+1,s,now,res);
                now.pop_back();
            }
        }
    }
    
    int findPa(int start,int fin,string &s)
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