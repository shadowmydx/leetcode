class Solution {
public:
    /*
    完整思路：
    0、定义dp[i]为：s[i]结尾的不重复子字符串最大长度。
    1、若s[i]在dp[i-1]的最长不重复子串中没有出现，则dp[i] = dp[i-1] + 1;反之若s[i]的出现序号为j，则dp[i] = i - 1 - j + 1;
    2、为了判断s[i]是否在dp[i-1]中出现，用一个hashmap记录当前字符的最大序号。
    */
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        unordered_map<char,int> dic;
        unordered_map<char,int>::iterator it; // map<key = s[i],value = i> 标记某个元素的最后出现位置。
        if (len == 0)
            return 0;
        int dp[len];
        for (int i = 0;i < len;i++)
            dp[i] = 0;
        dp[0] = 1;
        dic[s[0]] = 0;
        for (int i = 1;i < len;i++)
        {
            int flag  = 0;
            it = dic.find(s[i]);
            if (it == dic.end())
            {
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                if (it->second < i - 1 - (dp[i-1] - 1)) // 当前一个重复的值位于dp[i-1]序列的前方时
                {
                    dp[i] = dp[i-1] + 1;
                }
                else
                {
                    dp[i] = i - it->second;// 省略了+1和-1
                }
            }
            dic[s[i]] = i;
        }
        int max = 1;
        for (int i = 0;i < len;i++)
        {
            if (dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};