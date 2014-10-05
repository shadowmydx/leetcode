class Solution {
public:
    struct point
    {
        int x;
        int y;
    };
    bool exist(vector<vector<char> > &board, string word) {
        int len1 = board.size();
        if (word == "")
            return true;
        if (!len1)
            return false;
        int len2 = board[0].size();
        vector<point> start;
        vector<vector<int> > mark(len1);
        point tmp;
        for (int i = 0;i < len1;i++)
            for (int j = 0;j < len2;j++)
            {
                if (word[0] == board[i][j])
                {
                    tmp.x = i;
                    tmp.y = j;
                    start.push_back(tmp);
                }
                mark[i].push_back(0);
            }
        for (int i = 0;i < start.size();i++)
        {
            mark[start[i].x][start[i].y] = 1;
            bool flag = dfs(start[i].x,start[i].y,word.substr(1),mark,board);
            if (flag)
                return flag;
            setZero(mark);
        }
        return false;
    }
    void setZero(vector<vector<int> > &mark)
    {
        for (int i = 0;i < mark.size();i++)
            for (int j = 0;j < mark[i].size();j++)
                mark[i][j] = 0;
    }
    bool dfs(int x,int y,string word,vector<vector<int> > &mark,vector<vector<char> > &board)
    {
        if (word == "")
            return true;

        int rowborder = mark.size();
        int colborder = mark[0].size();
        bool flag = false;
        if (x - 1 >= 0 && mark[x-1][y] == 0)
        {
            if (board[x-1][y] == word[0])
            {
                mark[x-1][y] = 1;
                flag = dfs(x-1,y,word.substr(1),mark,board);
                if (flag)
                    return true;
                mark[x-1][y] = 0; // 当走不通后，回退时，走过的格子都必须恢复成能走的状态
            }
        }
        if (x + 1 < rowborder && mark[x+1][y] == 0)
        {
            if (board[x+1][y] == word[0])
            {
                mark[x+1][y] = 1;
                flag = dfs(x+1,y,word.substr(1),mark,board);
                if (flag)
                    return true;
                mark[x+1][y] = 0;
            }
        }
        if (y - 1 >= 0 && mark[x][y-1] == 0)
        {
            if (board[x][y-1] == word[0])
            {
                mark[x][y-1] = 1;
                flag = dfs(x,y-1,word.substr(1),mark,board);
                if (flag)
                    return true;
                mark[x][y-1] = 0;
            }
        }
        if (y + 1 < colborder && mark[x][y+1] == 0)
        {
            if (board[x][y+1] == word[0])
            {
                mark[x][y+1] = 1;
                flag = dfs(x,y+1,word.substr(1),mark,board);
                if (flag)
                    return true;
                mark[x][y+1] = 0;
            }
        }
        return flag;
    }
};