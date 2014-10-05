class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int len;
        int j;
        int flag = 0;
        string ans,small,big;
        string one = "1";
        if (len1 > len2)
        {
            ans = a;
            big = a;
            small = b;
            j = len2 - 1;
            len = len1;
        }
        else
        {
            ans = b;
            big = b;
            small = a;
            j = len1 - 1;
            len = len2;
        }
        for (int i = len - 1;i >= 0;i--)
        {
            if (j >= 0)
            {
                int num1 = small[j] - '0';
                int num2 = big[i] - '0';
                int val  = num1 + num2 + flag;
                switch(val)
                {
                    case 0 : ans[i] = '0';
                             flag = 0;
                             break;   
                    case 1 : ans[i] = '1';
                             flag = 0;
                             break;
                    case 2 : ans[i] = '0';
                             flag = 1;
                             break;
                    case 3 : ans[i] = '1';
                             flag = 1;
                             break;
                }
                j --;
            }
            else if (flag > 0)
            {
                int num = ans[i] - '0';
                int val = num + flag;
                if (val == 2)
                {
                    ans[i] = '0';
                    flag = 1;
                }
                else if (val == 1)
                {
                    ans[i] = '1';
                    flag = 0;
                }
                else
                {
                    ans[i] = '0';
                    flag = 0;
                }
            }
            else
                break;
        }
        if (flag > 0)
            ans = one + ans;
        return ans;
    }
};