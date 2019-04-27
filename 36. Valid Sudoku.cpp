/*
方法一：用9*9、9*9、3*3的数组分别记录行、列、块的9个数字，重复就报错
方法二：用三个一维数组记录（例：row[i] ^= (1 << d - 1)），时间复杂度与一一样，但空间复杂度大大下降
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> block(9, vector<int>(9, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                
                if (row[i][board[i][j]-'0'-1] == 0)
                    row[i][board[i][j]-'0'-1] = 1;
                else
                    return false;
                
                if (col[j][board[i][j]-'0'-1] == 0)
                    col[j][board[i][j]-'0'-1] = 1;
                else
                    return false;
                
                if (block[(i/3)*3 + j/3][board[i][j]-'0'-1] == 0)
                    block[(i/3)*3 + j/3][board[i][j]-'0'-1] = 1;
                else
                    return false;
            }
        }
        return true;
    }
};