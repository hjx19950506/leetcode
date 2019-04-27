/*
方法一：方法二改进版，基本下棋类的都是回溯
方法二：能解，但是时间复杂度太大，
主要是每次Try都是用上一题的程序做一次全局检查，想改进的话就是只检查该行该列就行了，改进得到方法一
*/

class Solution {
public:
    vector<vector<int>> row_buf;
    vector<vector<int>> col_buf;
    vector<vector<int>> block_buf;

    bool Try(int row, int col, char num) {
        if (row_buf[row][num - '0' - 1] == 1)
            return false;
        if (col_buf[col][num - '0' - 1] == 1)
            return false;
        if (block_buf[(row / 3) * 3 + col / 3][num - '0' - 1] == 1)
            return false;
        return true;
    }

    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] == '.') {
            for (char i = '1'; i <= '9'; i++) {
                if (Try(row, col, i) == true) {
                    board[row][col] = i;
                    row_buf[row][i - '0' - 1] = 1;
                    col_buf[col][i - '0' - 1] = 1;
                    block_buf[(row / 3) * 3 + col / 3][i - '0' - 1] = 1;

                    if (col < 8) {
                        if (dfs(board, row, col + 1))
                            return true;
                    }
                    else if (row < 8) {
                        if (dfs(board, row + 1, 0))
                            return true;
                    }
                    else
                        return true;
                    board[row][col] = '.';
                    row_buf[row][i - '0' - 1] = 0;
                    col_buf[col][i - '0' - 1] = 0;
                    block_buf[(row / 3) * 3 + col / 3][i - '0' - 1] = 0;
                }
            }
        }
        else {
            if (col < 8) {
                if (dfs(board, row, col + 1))
                    return true;
            }
            else if (row < 8) {
                if (dfs(board, row + 1, 0))
                    return true;
            }
            else
                return true;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<int> tmp(9,0);
        for (int i = 0; i < 9; i++) {
            row_buf.push_back(tmp);
            col_buf.push_back(tmp);
            block_buf.push_back(tmp);
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                row_buf[i][board[i][j] - '0' - 1] = 1;
                col_buf[j][board[i][j] - '0' - 1] = 1;
                block_buf[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1] = 1;
            }
        }
        dfs(board, 0, 0);
        return;
    }
};








class Solution {
public:
	vector<vector<char>> res;
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<int>> row(9, vector<int>(9, 0));
		vector<vector<int>> col(9, vector<int>(9, 0));
		vector<vector<int>> block(9, vector<int>(9, 0));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;

				if (row[i][board[i][j] - '0' - 1] == 0)
					row[i][board[i][j] - '0' - 1] = 1;
				else
					return false;

				if (col[j][board[i][j] - '0' - 1] == 0)
					col[j][board[i][j] - '0' - 1] = 1;
				else
					return false;

				if (block[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1] == 0)
					block[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1] = 1;
				else
					return false;
			}
		}
		return true;
	}
	bool Try(vector<vector<char>>& board, int row, int col, char num) {
		vector<vector<char>> tmp = board;
		tmp[row][col] = num;
		return isValidSudoku(tmp);
	}

	void dfs(vector<vector<char>>& board, int row, int col) {
		if (board[row][col] == '.') {
			for (char i = '1'; i <= '9'; i++) {
				if (Try(board, row, col, i) == true) {
					board[row][col] = i;
					if (col < 8)
						dfs(board, row, col + 1);
					else if (row < 8)
						dfs(board, row + 1, 0);
					else {
						res = board;
					}
						
				}
			}
			board[row][col] = '.';
		}
		else {
			if (col < 8)
				dfs(board, row, col + 1);
			else if (row < 8)
				dfs(board, row + 1, 0);
			else {
				res = board;
			}
		}
	}

	void solveSudoku(vector<vector<char>>& board) {
		dfs(board, 0, 0);
		board = res;
		return;
	}
};