class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        /*
        对于某个数而言，是否存在连续？看是否存在+1和-1.如何高效做到这一点？hash
        */
        unordered_set<int> dealed;
        unordered_set<int> val;
        int max = 0;
        int len = 1;
        for (int i = 0;i < num.size();i++)
            val.insert(num[i]);
        unordered_set<int>::iterator it1,it2,it3;
        for (int i = 0;i < num.size();i++)
        {
            if ((it1 = dealed.find(num[i])) != dealed.end())
                continue;
            else
            {
                len = 1;
                int right = num[i] - 1;
                int left  = num[i] + 1;
                it2 = val.find(num[i] + 1);
                it3 = val.find(num[i] - 1);
                while (it2 != val.end())
                {
                    dealed.insert(left);
                    len ++;
                    left ++;
                    it2 = val.find(left);
                }
                while (it3 != val.end())
                {
                    dealed.insert(right);
                    right --;
                    len ++;
                    it3 = val.find(right);
                }
                if (len > max)
                    max = len;
            }
        }
        return max;
    }
};