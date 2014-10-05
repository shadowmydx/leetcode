class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        vector<int> tmp(numbers.begin(),numbers.end());
        sort(numbers.begin(),numbers.end());
        int sptr = 0,eptr = numbers.size() - 1,res = 0;
        bool flag1 = true,flag2 = true;
        while (sptr != eptr)
        {
            res = numbers[sptr] + numbers[eptr];
            if (res == target) break;
            else if (res < target)
                sptr ++;
            else if (res > target)
                eptr --;
        }
        for (int i = 0;i < tmp.size();i++)
        {
            if (flag1 && tmp[i] == numbers[sptr]){
                sptr = i;
                flag1 = false;
            }
            else if (flag2 && tmp[i] == numbers[eptr]){
                eptr = i;
                flag2 = false;
            }
        }
        if (sptr < eptr) {
            result.push_back(sptr + 1);
            result.push_back(eptr + 1);
        } else {
            result.push_back(eptr + 1);
            result.push_back(sptr + 1);
        }
        
        return result;
    }
};