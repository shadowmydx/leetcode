class Solution {
public:
    char dp[1500][1500];
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        if (!len)
            return true;
        int flag = findRes(s,dict,0,len - 1);
        return flag == 1 ? true : false;
    }
    
    int findRes(string &s,unordered_set<string> &dict,int start,int fin)
    {
        if (start > fin)
            return -1;
        if (dp[start][fin] != 0)
            return dp[start][fin];
        int len  = fin - start + 1;
        int flag = -1;
        unordered_set<string>::iterator it;
        for (int i = 1;i <= len;i++)
        {
            it = dict.find(s.substr(start,i));
            if (it != dict.end())
            {
                if (i == len)
                    return dp[start][fin] = 1;
                dp[start][i-1] = 1;
                flag = findRes(s,dict,start + i,fin);
                if (flag == 1)
                    return dp[start][fin] = 1;
            }
        }
        return dp[start][fin] = flag;
    }
};