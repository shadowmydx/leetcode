class Solution {
public:
    // 需要用stack模拟深搜，直接递归爆栈
    void solve(vector<vector<char>> &board) {
       int len1 = board.size(); // how many rows?
       if (len1 <= 2)
            return;
       int len2 = board[0].size(); // how many cols?
       if (len2 <= 2)
            return;
       vector<vector<bool> > map(len1);

       for (int i = 0;i < len1;i++)
       {
            for (int j = 0;j < len2;j++)
                    map[i].push_back(false);
       }
       
       travelMap(map,board);
       
       for (int i = 0;i < len1;i++)
       {
            for (int j = 0;j < len2;j++)
                if (map[i][j] == false)
                    board[i][j] = 'X';
       }       
       return;
    }
    void travelMap(vector<vector<bool> > &map,vector<vector<char> > &board)
    {
        int len2 = board[0].size(); // how many cols?
        int len1 = board.size();

        int startX,startY;
        for (int i = 0;i < len2;i++) // first row
        {
            if (board[0][i] == 'O' && map[0][i] == false)
            {
                startX = 0;
                startY = i;
                DFS(board,map,startX,startY);
            }
        }
        for (int i = 0;i < len1;i++) // first col
        {
            if (board[i][0] == 'O' && map[i][0] == false)
            {
                startX = i;
                startY = 0;
                DFS(board,map,startX,startY);
            }
        }
        for (int i = 0;i < len2;i++) // last row
        {
            if (board[len1-1][i] == 'O' && map[len1-1][i] == false)
            {
                startX = len1 - 1;
                startY = i;
                DFS(board,map,startX,startY);
            }
        }
        for (int i = 0;i < len1;i++) // last col
        {
            if (board[i][len2-1] == 'O' && map[i][len2-1] == false)
            {
                startX = i;
                startY = len2 - 1;
                DFS(board,map,startX,startY);
            }
        }
        return;
    }
    void DFS(vector<vector<char> > &board,vector<vector<bool> > &map,int x,int y)
    {
        int border1 = board.size();
        int border2 = board[0].size();
        stack<int> forX;
        stack<int> forY;
        forX.push(x);
        forY.push(y);
        while (!forX.empty())
        {
            x = forX.top();
            y = forY.top();
            map[x][y] = true;
            forX.pop();
            forY.pop();
            if (x - 1 >= 0 && map[x-1][y] == false && board[x-1][y] == 'O') // up
            {
                forX.push(x-1);
                forY.push(y);
            }
            if (x + 1 < border1 && map[x+1][y] == false && board[x+1][y] == 'O') // down
            {
                forX.push(x+1);
                forY.push(y);
            }
            if (y - 1 >= 0 && map[x][y-1] == false && board[x][y-1] == 'O') // left
            {
                forX.push(x);
                forY.push(y-1);
            }
            if (y + 1 < border2 && map[x][y+1] == false && board[x][y+1] == 'O') // right
            {
                forX.push(x);
                forY.push(y+1);
            }
        }
    }
};