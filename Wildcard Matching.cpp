class Solution {
public:
    int dp[500][500];
    bool isMatch(const char *s, const char *p) {
        int len1 = strlen(s);
        int len2 = strlen(p);
        if (!len1 && !len2)
            return true;
        if (len1 && !len2)
            return false;
        const char* tmp = p;  
        int cnt = 0;  
        while (*tmp != '\0') 
            if (*(tmp++) != '*') 
                cnt++;  
        if (cnt > len1) 
            return false;  
        init(s,p,len1,len2);
        if (ismatch(s,p,len1,len2))
            return true;
        else
            return false;
    }
    
    int ismatch(const char *s,const char *p,int lens,int lenp)
    {
        for (int i = 1;i <= lens;i++)
        {
            for (int j = 1;j <= lenp;j++)
            {
                if (s[i-1] == p[j-1] || p[j-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*')
                {
                    dp[i][j] = (dp[i][j-1] | dp[i-1][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return dp[lens][lenp];
    }
    
    void init(const char *s,const char *p,int lens,int lenp)
    {
        int i = 1;
        while (i <= lenp && p[i-1] == '*')
        {
            dp[0][i] = 1;
            i ++;
        }
        dp[0][0] = 1;
    }
    
};