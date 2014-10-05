class Solution 
{
public:
		int sel[9][9][10];
		Solution()
		{
			for (int i = 0;i < 9;i++)
				for (int j = 0;j < 9;j++)
					for (int p = 0;p < 10;p++)
						sel[i][j][p] = 1;
		}
    void solveSudoku(vector<vector<char> > &board) 
		{
			vector<vector<int> > res;
    	init(board);
			tryRow(0,res);
		//	printResult(res);

			int len1 = board.size();
			int len2 = board[0].size();
			for (int i = 0;i < len1;i++)
				for (int j = 0;j < len2;j++)
					if (board[i][j] == '.')
						board[i][j] = res[i][j] + '0';
    }
		bool tryRow(int row,vector<vector<int> > &res)
		{
			if (row >= 9)
			{
				return true;
			}
			bool flag = false;
			vector<int> now(10);
			flag = fillRow(row,0,now,res);
			return flag;
		}

		bool fillRow(int row,int col,vector<int> &now,vector<vector<int> > &res)
		{
			bool flag = false;
			if (col >= 9)
			{
				res.push_back(now);
				flag = tryRow(row + 1,res);
				if (flag == false)
					res.pop_back();
				return flag;
			}
			if (sel[row][col][0] != 0)
			{
					now[col] = sel[row][col][0];
					flag = fillRow(row,col + 1,now,res);
					return flag;
			}
			int hash[10] = {0}; // now中现存的数为1,该数组中为1的数不能选
			for (int i = col - 1;i >= 0;i--)
				hash[now[i]] = 1;
			update(row,col,hash,res);
		  for (int i = 1;i <= 9;i++)
			{
				if (hash[i] == 0 && sel[row][col][i] == 1)
				{
					now[col] = i;
					flag = fillRow(row,col + 1,now,res);
					if (flag)
						return true;
				}
			}	
			return flag;
		}	
		
		void update(int row,int col,int *hash,vector<vector<int> > &res)
		{
			int top  = getTop(row);
			int left = getLeft(col);
			for (int i = row - 1;i >= 0;i--) // 既有结果列中的数不能选
			{
					hash[res[i][col]] = 1;
			}
			if (row > top)
			{
				int count = row - top;
				for (int i = 0;i < count;i++)
					for (int j = 0;j < 3;j++)
						hash[res[top+i][left+j]] = 1;
			}
		}

		void init(vector<vector<char> > &board)
		{
			int len1 = board.size();
			int len2 = board[0].size();
			for (int i = 0;i < len1;i++)
				for (int j = 0;j < len2;j++)
				{
					if (board[i][j] != '.')
					{
						setRow(i,board[i][j] - '0');
						setCol(j,board[i][j] - '0');
						setCel(i,j,board[i][j] - '0');
						sel[i][j][0] = board[i][j] - '0';	
					}
					else
						sel[i][j][0] = 0;
				}
		}
		void setRow(int i,int num)
		{
			for (int j = 0;j < 9;j++)
			{
				sel[i][j][num] = 0;
			}
		}
		void setCol(int j,int num)
		{
			for (int i = 0;i < 9;i++)
			{
				sel[i][j][num] = 0;
			}
		}
		void setCel(int x,int y,int num)// 求方格的左上坐标
		{
			int top,left;
			top  = getTop(x);
			left = getLeft(y); 
			for (int i = 0;i < 3;i++)
				for (int j = 0;j < 3;j++)
					sel[i+top][j+left][num] = 0;
		}

		int getLeft(int col)
		{
			int tmp;
			int left;
			tmp = col % 9;
			if (tmp >= 6)
			{
				left = 6;
			}
			else if (tmp >= 3)
				left = 3;
			else
				left = 0;
			return left;
		}

		int getTop(int row)
		{
			int tmp;
			int top;
			tmp = row % 9;
			if (tmp >= 6)
			{
				top = 6;
			}
			else if (tmp >= 3)
			{
				top = 3;
			}
			else
				top = 0;
			return top;
		}
		void test()
		{
			for (int i = 0;i < 9;i++)
				for (int j = 0;j < 9;j++)
					for (int num = 0;num < 10;num++)
						if (sel[i][j][0] == 0)
						{
							cout << "在格子" << i << " " << j << " 该格有数字" << endl;
							break;
						}
						else
						{
							if (sel[i][j][num] == 1 && num != 0)
								cout << "在格子" << i << " " << j << " 该格候选数为" << num << endl;
						}

		}
		void printResult(vector<vector<int> > &res)
		{
			for (int i = 0;i < 9;i++)
			{
				for (int j = 0;j < 9;j++)
					cout << res[i][j] << " ";
				cout << endl;
			}
		}
};