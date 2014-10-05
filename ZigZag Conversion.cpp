class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.size();
        string tmp;
        tmp = s;
        if (nRows == 1)
            return s;
        int start = 0;
        int gap = (nRows - 1) * 2;
        int ligap = gap;
        for (int i = 0;i < nRows;i++)
        {
            int flag = i;
            while (flag < len)
            {
                tmp[start++] = s[flag];
                if (i != 0 && i != nRows - 1 && ligap > 0 && flag + ligap < len)
                {
                    tmp[start++] = s[flag + ligap];
                }
                flag += gap;
            }
            ligap -= 2;
        }
        return tmp;
    }
};