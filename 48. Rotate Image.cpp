/*
先做上下翻转，再做对角线反转
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            swap(matrix[i], matrix[n-1 - i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};