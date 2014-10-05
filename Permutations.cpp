class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> mark;
        vector<int> now;
        for (int i = 0;i < num.size();i++)
            mark.push_back(0);
        recurPer(res,now,num,mark);
        return res;
    }
    
    void recurPer(vector<vector<int> > &res,vector<int> &now,vector<int> &num,vector<int> &mark)
    {
        int flag = 0;
        for (int i = 0;i < num.size();i++)
        {
            if (mark[i] == 0)
            {
                flag = 1;
                mark[i] = 1;
                now.push_back(num[i]);
                recurPer(res,now,num,mark);
                now.pop_back();
                mark[i] = 0;
            }
        }
        if (!flag)
            res.push_back(now);
    }
};