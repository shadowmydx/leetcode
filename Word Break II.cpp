class Solution {
public:
    /*
     *设dp[i]为当以i为结尾时，若可分割，则dp[i]为以i结尾的单词长度
     */
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int len = s.size();
        int tmplen;
        vector<string> res;
        vector<vector<int> > dp(len);
        unordered_set<string>::iterator it;
        if (!len)
            return res;
        for (int i = 0;i < len;i++)
        {
            for (int j = i;j >= 0;j--)
            {
                int tmplen = i - j + 1;
                it = dict.find(s.substr(j,tmplen));
                if (it != dict.end())
                {
                    if (j == 0)
                        dp[i].push_back(tmplen);
                    else
                    {
                        if (!dp[j-1].empty())
                            dp[i].push_back(tmplen);
                    }
                }
            }
        }
        findRes(res,dp,len-1,s,"");
        return res;
    }
    
    void findRes(vector<string> &res,vector<vector<int> > &dp,int i,string &s,string pre)
    {
        if (i  < 0)
        {
            res.push_back(pre);
            return;
        }
        int len = dp[i].size();
        if (!len)
            return;
        string tmp;
        for (int j = 0;j < len;j++)
        {
            int start = i - dp[i][j] + 1;
            tmp = s.substr(start,dp[i][j]);
            if (pre != "")
                tmp = tmp + " ";
            tmp = tmp + pre;
            findRes(res,dp,start-1,s,tmp);
        }
    }
    
};