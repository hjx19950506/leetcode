/*
和上题没什么区别
*/


class Solution {
public:
    bool Try(vector<int>& num, int row, int col) {
	int i = 1;
	while (i < row) {
		if (num[i] == col || (abs(row - i) == abs(col - num[i])))
			return false;
		i++;
	}
	return true;
}
void place(int n, int row, vector<int>& num, vector<vector<int>>& nums) {
	if (row > n) {
		nums.push_back(num);
	}
	else {
		for (int col = 1; col <= n; col++) {
			if (Try(num, row, col)) {
				num[row] = col;
				place(n, row + 1, num, nums);
			}
		}
	}
}
    int totalNQueens(int n) {
    vector<vector<int>> buf;
	vector<int> tmp(n+1, 0);
	place(n, 1, tmp, buf);

	return buf.size();
    }
};