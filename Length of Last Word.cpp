class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        if (!len)
            return 0;
        char tar[len];
        int flag = getLastWord(tar,s,len);
        if (flag)
            return strlen(tar);
        else
            return 0;
    }
    int getLastWord(char *tar,const char *s,int length)
    {
        int j = 0;
        int i = length - 1;
        while (i >= 0 && s[i--] == ' ')
            ;
        i ++;
        if (s[i] == ' ')
            return 0;
        while (i >= 0 && s[i] != ' ')
            tar[j++] = s[i--];
        tar[j] = '\0';
        return 1;
    }
};