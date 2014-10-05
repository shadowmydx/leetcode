class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /*
        思路：动态规划
        方案：0.设置一个储存string的二维数组，其中res[i]代表有i对括号时的所有情况。
              1.已知res[i] ,求res[i+1]时，有'(' + res[start][...] + ')' + res[fin][...]，其中start + fin = i
        */
        vector<vector<string> > res;
        vector<string> now;
        now.push_back("");
        res.push_back(now);
        now.clear();
        now.push_back("()");
        res.push_back(now);
        now.clear();
        for (int i = 2;i <= n;i++)
        {
            int start = 0,fin = i - 1;
            for (;start <= i - 1;start ++)
            {
                fin = i - 1 - start;
                for (int j = 0;j < res[start].size();j++)
                {
                    for (int q = 0;q < res[fin].size();q++)
                    {
                        string tmp = '(' + res[start][j] + ')' + res[fin][q];
                        now.push_back(tmp);
                    }
                }
            }
            res.push_back(now);
            now.clear();
        }
        return res[res.size() - 1];
    }
};