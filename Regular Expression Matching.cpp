class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!*s || !*p)
            if (*s == '\0' && *p == '\0')
                return true;
            else if (*s == '\0') // s匹配完后，如果p全是*对，那么成功
            {
                int i = 0;
                while (p[i])
                {
                    if (p[i+1] != '*')
                        return false;
                    i += 2;
                }
                return true;
            }
            else
                return false;
        bool flag = false;
        int slen = strlen(s);
        if (p[1] != '\0' && p[1] == '*')
        {
            if (p[0] == '.')
            {
                for (int i = 0;i <= slen;i++)
                {
                    flag = isMatch(s + i,p + 2);
                    if (flag == true)
                        break;
                }
            }
            else
            {
                int count = 0;
                if (p[0] == s[0])
                {
                    for (int i = 0;;i++)
                    {
                        if (i != 0 && p[0] != s[i]) // 一个都不吃 + 慢慢吃 + 全部都吃 count标记全部都吃的情况
                            count  = 1;
                        flag = isMatch(s + i,p + 2);
                        if (flag == true)
                            break;
                        if (count == 1)
                            break;
                    }
                }
                else 
                    flag = isMatch(s,p + 2);
            }
        }
        else
        {
            if (p[0] == '.')
                flag = isMatch(s + 1,p + 1);
            else if (p[0] == s[0])
                flag = isMatch(s + 1,p + 1);
            else
                return false;
        }
        return flag;
    }
};