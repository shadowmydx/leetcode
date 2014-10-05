class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int len1 = board.size();
        if (!len1)
            return true;
        int len2 = board[0].size();
        for (int i = 0;i < len1;i++)
            for (int j = 0;j < len2;j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j];
                    bool flag1 = checkRow(i,j,num,board);
                    bool flag2 = checkCol(i,j,num,board);
                    bool flag3 = checkCel(i,j,num,board);
                    if (!flag1 || !flag2 || !flag3)
                        return false;
                }
            }
        return true;
    }
    bool checkRow(int row,int col,int num,vector<vector<char> > &board)
    {
        for (int i = 0;i < 9;i++)
        {
            if (col == i)
                continue;
            if (board[row][i] == num)
                return false;
        }
        return true;
    }
    bool checkCol(int row,int col,int num,vector<vector<char> > &board)
    {
        for (int i = 0;i < 9;i++)
        {
            if (row == i)
                continue;
            if (board[i][col] == num)
                return false;
        }
        return true;
    }
    bool checkCel(int row,int col,int num,vector<vector<char> > &board)
    {
        int top  = getTop(row);
        int left = getTop(col);
        for (int i = 0;i < 3;i++)
            for (int j = 0;j < 3;j++)
            {
                if (top + i == row && left + j == col)
                    continue;
                if (board[top+i][left+j] == num)
                    return false;
            }
        return true;
    }
    int getTop(int row)
    {
        int tmp = row % 9;
        if (tmp >= 6)
            return 6;
        else if (tmp >= 3)
            return 3;
        else
            return 0;
    }
};