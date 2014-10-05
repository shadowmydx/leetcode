class Solution {
public:
    int reverse(int x) {
        int flag;
        int start = 1;
        vector<int> res;
        int sum = 0;
        flag = x > 0 ? 1 : -1;
        x *= flag;
        while (x)
        {
            res.push_back(x % 10);
            x /= 10;
            start *= 10;
        }
        start /= 10;
        for (int i = 0;i < res.size();i++)
        {
            sum += res[i] * start;
            start /= 10;
        }
        return sum * flag;
    }
};