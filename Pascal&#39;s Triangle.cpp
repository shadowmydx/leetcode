class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        int flag = 0;
        int start = 1;
        vector<int> ho;
        vector<vector<int> > tmp;
        vector<vector<int> > res;
        tmp.push_back(ho);
        tmp.push_back(ho);
        while (start <= numRows)
        {
            tmp[flag].push_back(1);
            if (start == 2)
                tmp[flag].push_back(1);
            else if (start > 2)
            {
                for (int i = 1;i < start - 1;i++)
                    tmp[flag].push_back(tmp[!flag][i-1] + tmp[!flag][i]);
                tmp[flag].push_back(1);
            }
            start ++;
            res.push_back(tmp[flag]);
            tmp[!flag].clear();
            flag = !flag;
        }
        return res;
    }
};