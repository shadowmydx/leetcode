class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len1 = strlen(needle);
        int len2 = strlen(haystack);
        if (len1 == 0)
            return haystack;
        if (len2 < len1)
            return NULL;
        int dic[len1];
        init(dic,len1,needle);
        int i,j;
        j = 0;
        for (int i = 0;i < len2;)
        {
            if (haystack[i] == needle[j])
            {
                j ++,i ++;
                if (j >= len1)
                {
                    return &haystack[i - len1];
                }
            }
            else if (j == 0)
            {
                i ++;
            }
            else
            {
                j = dic[j];
            }
        }
        return NULL;
    }
    
    void init(int dic[],int len,char *needle)
    {
        dic[0] = 0;
        if (len > 1)
            dic[1] = 0;
        for (int i = 2;i < len;i++)
        {
            int flag = 0;
            if (needle[dic[i-1]] == needle[i-1])
            {
                flag = 1;
                dic[i] = dic[i-1] + 1;
            }
            else
            {
                for (int j = i - 2;j >= 2;j --)
                {
                    if (needle[dic[j]] == needle[i-1]) // 看看前一个元素和谁的结尾匹配
                    {
                        flag = 1;
                        dic[i] = dic[j] + 1;
                        break;
                    }
                }
            }
            if (!flag)
                dic[i] = 0;
        }
    }
};