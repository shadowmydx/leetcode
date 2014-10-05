class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        vector<int> tmp;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                tmp.push_back(0);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        recursionGe(res,1,n,0,0);
        return res;
    }
    void recursionGe(vector<vector<int> > &res,int num,int n,int x,int y)
    {
        if (n <= 0)
            return;
        res[x][y] = num++;
        for (int i = 1;i < n;i++)
            res[x][++y] = num++;
        for (int i = 1;i < n;i++)
            res[++x][y] = num++;
        for (int i = 1;i < n;i++)
            res[x][--y] = num++;
        for (int i = 1;i < n - 1;i++)
            res[--x][y] = num++;
        recursionGe(res,num,n - 2,x,y + 1); // n的递增幅度是2.因为最右边也不是新蛇的范围.
    }
};