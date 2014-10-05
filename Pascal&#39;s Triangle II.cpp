class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int flag = 0;
        int mak = 0;
        vector<vector<int> > res;
        vector<int> tmp;
        res.push_back(tmp);
        res.push_back(tmp);
        res[flag].push_back(1);
        while (mak != rowIndex)
        {
            res[!flag].push_back(1);
            for (int i = 1;i <= mak;i++)
                res[!flag].push_back(res[flag][i] + res[flag][i-1]);
            res[!flag].push_back(1);
            res[flag].clear();
            flag = !flag;
            mak ++;
        }
        return res[flag];
    }
};