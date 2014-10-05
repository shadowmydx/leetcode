class Solution {
public:
    /*
    0、宽度优先遍历不能使用，因为扩展的子节点过多，会爆。
    1、DFS，维护两个指针标号，一个指向目标字符串，设为i；一个指向匹配字符串，设为j；
    2、定义dp[i][j]为：当指针指向i和j时所需要的最小值。
    3、若删除，则j ++ i不变；若插入，则i ++ j不变；若代替，则i++，j++
    4、若当前符号相等，则i ++ j ++
    */
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int max;
        max = len1 > len2 ? len1 : len2;
        vector<vector<int> > dp;
        vector<int> tmp;
        for (int i = 0;i < max + 1;i++)
        {
            for (int j = 0;j < max + 1;j++)
            {
                tmp.push_back(~(1 << 31));
            }
            dp.push_back(tmp);
            tmp.clear();
        }
        int min = dfs(0,0,len1,len2,0,max,word1,word2,dp);
        return min;
    }
    int dfs(int tar,int pat,int len1,int len2,int now,int max,string &word1,string &word2,vector<vector<int> > &dp)
    {
        if (tar >= len2 && pat >= len1)
            return dp[tar][pat] = 0;
        if (dp[tar][pat] != ~(1 << 31))
            return dp[tar][pat];        
        //if (now > max)
          //  return 1;
        if (tar < len2 && pat < len1 && word2[tar] == word1[pat])
        {
            return dp[tar][pat] = dfs(tar + 1,pat + 1,len1,len2,now,max,word1,word2,dp);
        }
        int a1,a2,a3;
        a1 = a2 = a3 = ~(1 << 31);
        if (tar < len2)
            a1 = dfs(tar + 1,pat,len1,len2,now + 1,max,word1,word2,dp); // insert
        if (pat < len1)
            a2 = dfs(tar,pat + 1,len1,len2,now + 1,max,word1,word2,dp); // delete
        if (pat < len1 && tar < len2)
            a3 = dfs(tar + 1,pat + 1,len1,len2,now + 1,max,word1,word2,dp); // replace
        a1 = a1 < a2 ? a1 : a2;
        return dp[tar][pat] = (a1 > a3 ? a3 : a1) + 1;
    }
};