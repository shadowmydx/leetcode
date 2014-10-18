class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size();
        if (!len)
            return "";
        char now;
        int  count = 0;
        while (count < strs[0].size()) // 因为用strs[0]作为参考now，所以用0的size
        {
            now = strs[0][count];
            for (int i = 0;i < len;i++)
            {
                if (count >= strs[i].size())
                    return strs[i];
                if (strs[i] == "")
                    return "";
                if (strs[i][count] != now)
                    return strs[i].substr(0,count);
            }
            count ++;
        }
        return strs[0];
    }
};