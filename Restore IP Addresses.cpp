class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string tmp;
        getItem(s,4,tmp,res);
        return res;
    }
    
    int getItem(string s,int num,string now,vector<string> &res)
    {
        if (s == "")
            return 0;
        int length = s.length();
        string tmp1,tmp2;
        int flag;
        if (num == 1)
        {
            int val = changeToNum(s);
            if (val > 255 || val == -1)
                return 0;
            now = now + s;
            res.push_back(now);
            return 1;
        }
        for (int i = 1;i <= 3;i++)
        {
            if (i >= length)
                return 0;
            tmp2 = now;
            tmp1 = s.substr(0,i);
            int val = changeToNum(tmp1);
            if (val > 255 || val == -1)
                continue;
            tmp2 = tmp2 + tmp1 + '.';
            flag = getItem(s.substr(i),num - 1,tmp2,res);
        }
        return 1;
    }
    int changeToNum(string s)
    {
        int len = s.length();
        if (len == 0)
            return -1;
        int res = 0;
        int wet = 1;
        int flag;
        switch (len)
        {
            case 1 : flag = 0;
                     break;
            case 2 : flag = 10;
                     break;
            case 3 : flag = 100;
                     break;
        }
        for (int i = len - 1;i >= 0;i--)
        {
            res += (s[i] - '0') * wet;
            wet *= 10;
        }
        if (res >= flag)
            return res;
        return -1;
    }
};