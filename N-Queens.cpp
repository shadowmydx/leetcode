class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> tmp(n);
        dfs(tmp,res,0,n);
        return res;
    }
    void dfs(vector<int> &arr,vector<vector<string> > &res,int step,int border)
    {
        if (step >= border)
        {
            vector<string> tmp = printResult(arr);
            res.push_back(tmp);
            return;
        }
        int hash[border];
        init(hash,arr,step,border);
        for (int i = 0;i < border;i++)
        {
            if (hash[i] == 1)
            {    
                arr[step] = i;
                dfs(arr,res,step+1,border);
            }
        }
    }
    
    void init(int hash[],vector<int> &arr,int step,int border)
    {
        int tmp;
        for (int i = 0;i < border;i++)
            hash[i] = 1;
        for (int i = 0;i < step;i++)
        {
            hash[arr[i]] = 0; // 竖线排除
            tmp = step - i;
            if (arr[i] - tmp >= 0)
                hash[arr[i]-tmp] = 0;
            if (arr[i] + tmp < border)
                hash[arr[i]+tmp] = 0;
        }
    }
    
    vector<string> printResult(vector<int> &arr)
    {
        int border = arr.size();
        vector<string> res;
        string tmp;
        for (int i = 0;i < arr.size();i++)
            tmp = tmp + '.';
        for (int i = 0;i < arr.size();i++)
        {
            tmp[arr[i]] = 'Q';
            res.push_back(tmp);
            tmp[arr[i]] = '.';
        }
        return res;
    }
};