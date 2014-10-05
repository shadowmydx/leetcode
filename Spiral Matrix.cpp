class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        int n = matrix[0].size(); 
        int m = matrix.size();
        findSpiral(matrix,res,n,m,0,0);
        return res;
    }
    void findSpiral(vector<vector<int> > &matrix,vector<int> &res,int clen,int rlen,int x,int y)
    {
        // 把只有一行或一列的情况单独处理。注意相对位置和绝对位置的关系。
        if (clen <= 0 || rlen <= 0)
            return;
        int startX = x,startY = y;
        if (rlen == 1)
        {
            for (int i = x;i < startX + clen;i++)
                res.push_back(matrix[x][i]);
        }
        else if (clen == 1)
        {
            for (int i = y;i < startY + rlen;i++)
                res.push_back(matrix[i][y]);
        }
        else
        {
            res.push_back(matrix[x][y]);
            while (y + 1 < startY + clen)
            {
                res.push_back(matrix[x][y + 1]);
                y ++;
            }
            while (x + 1 < startX + rlen)
            {
                res.push_back(matrix[x + 1][y]);
                x ++;
            }
            while (y - 1 >= startY)
            {
                res.push_back(matrix[x][y - 1]);
                y --;
            }
            while (x - 1 >= startX + 1)
            {
                res.push_back(matrix[x - 1][y]);
                x --;
            }
            findSpiral(matrix,res,clen - 2,rlen - 2,x,y + 1);
        }
    }
};