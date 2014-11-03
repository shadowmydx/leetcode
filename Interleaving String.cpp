class Solution {
public:
    string t1,t2,t3;
    char dp[600][600]; // 没处理过就是0，处理了可以就是1，不行就是2 
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3)
            return false;
        if (len1 == 0)
            return s2 == s3 ? true : false;
        if (len2 == 0)
            return s1 == s3 ? true : false;
        t1 = s1;
        t2 = s2;
        t3 = s3;
        return trueStuff(0,0,len1,len2);
    }
    bool trueStuff(int m,int n,int len1,int len2) // m is index for s1,n is index for s2.
    {
        if (m >= len1 && n >= len2)
            return true;
        if (dp[m][n] != 0)
            return dp[m][n] == 1 ? true : false;
        bool tmp = false; // mark if dp[m][n] can do the right thing.
        if (m >= len1)
            tmp = (t2[n] == t3[m+n] ? trueStuff(m,n + 1,len1,len2) : false);
        else if (n >= len2)
            tmp = (t1[m] == t3[m+n] ? trueStuff(m + 1,n,len1,len2) : false);
        else if (t1[m] == t2[n] && t1[m] == t3[m+n])
            tmp = (trueStuff(m + 1,n,len1,len2) || trueStuff(m,n + 1,len1,len2));
        else if (t1[m] == t3[m+n])
            tmp = trueStuff(m + 1,n,len1,len2);
        else if (t2[n] == t3[m+n])
            tmp = trueStuff(m,n + 1,len1,len2);
        else
            tmp = false;
        dp[m][n] = (tmp == true ? 1 : 2);
        return tmp;
    }
};