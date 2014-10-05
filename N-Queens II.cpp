class Solution {
public:
    int total;
    int totalNQueens(int n) {
        total = 0;
        vector<int> arr(n);
        dfs(arr,0,n);
        return total;
    }
    void dfs(vector<int> &arr,int step,int border)
    {
        if (step >= border)
        {
            total ++;
            return;
        }
        int hash[border];
        init(hash,arr,step,border);
        for (int i = 0;i < border;i++)
        {
            if (hash[i] == 1)
            {    
                arr[step] = i;
                dfs(arr,step+1,border);
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
};