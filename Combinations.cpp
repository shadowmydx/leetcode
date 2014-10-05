class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> now;
        geneCom(k,1,n,res,now);
        return res;
    }
    // k为组合数。min 为所能允许的最小数。border 为终点数。
    // 任意一个组合，内部元素是升序排列。
    void geneCom(int k,int min,int border,vector<vector<int> > &res,vector<int> &now) 
    {
        if (k == 0)
        {
            res.push_back(now);
            return;
        }
        for (int i = min;i <= border;i++)
        {
            now.push_back(i);
            geneCom(k - 1,i + 1,border,res,now);
            now.pop_back();
        }
    }
};