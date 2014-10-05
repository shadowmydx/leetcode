class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int flag = 1;
        int i = digits.size() - 1;
        while (i >=0 && flag)
        {
            int num = digits[i] + flag;
            if (num >= 10)
            {
                digits[i--] = 0;
                flag = 1;
            }
            else 
            {
                digits[i] = num;
                flag = 0;
            }
        }
        if (i < 0)
        {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};