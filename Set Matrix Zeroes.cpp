class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        /*
        方法：原理上是标记需要清零的行和列，节省空间的办法在于利用既有的空间来标记。
              注意：第一行和第一列是否需要全部清零需要作为特例来判断.
        */
        int m = matrix.size(),n = 0;
        if (m)
            n = matrix[0].size();
        int flagcol = 0,flagrow = 0;
        for (int i = 0;i < m;i++)
            if (matrix[i][0] == 0)
                flagcol = 1;
        for (int i = 0;i < n;i++)
            if (matrix[0][i] == 0)
                flagrow = 1;
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0; // 所在列标记为0.
                    matrix[i][0] = 0; // 所在行标记为0.
                }
            }
        for (int i = 1;i < m;i++)
        {
            if (matrix[i][0] == 0)
                setRow(matrix,i);
        }
        for (int i = 1;i < n;i++)
        {
            if (matrix[0][i] == 0)
                setCol(matrix,i);
        }
        if (flagcol)
            setCol(matrix,0);
        if (flagrow)
            setRow(matrix,0);
    }
    void setRow(vector<vector<int> > &matrix,int row)
    {
        int len = matrix[0].size();
        for (int i = 0;i < len;i++)
            matrix[row][i] = 0;
    }
    void setCol(vector<vector<int> > &matrix,int col)
    {
        int len = matrix.size();
        for (int i = 0;i < len;i++)
            matrix[i][col] = 0;
    }
};