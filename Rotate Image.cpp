class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        //求对称矩阵，再交换列
        toSymmetric(matrix);
        int i = 0,j = matrix[0].size() - 1;
        while (i < j)
        {
            swapCols(matrix,i++,j--);
        }
    }
    void toSymmetric(vector<vector<int> > &matrix)
    {
        int n = matrix[0].size();
        for (int i = 0;i < n;i++)
        {
            for (int j = i;j < n;j++)
            {
                swap(&matrix[i][j],&matrix[j][i]);
            }
        }
    }
    void swapCols(vector<vector<int> > &matrix,int col1,int col2)
    {
        int n = matrix[0].size();
        for (int i = 0;i < n;i++)
        {
            swap(&matrix[i][col1],&matrix[i][col2]);
        }
    }
    void swap(int *a,int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};