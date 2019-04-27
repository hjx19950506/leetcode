/*
»ØËÝ·¨
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

vector<vector<string>> solveNQueens(int n) {
	vector<vector<int>> buf;
	vector<int> tmp(n+1, 0);
	place(n, 1, tmp, buf);

	vector<vector<string>> res;
	string str;
	for (int i = 0; i < n; i++)
		str += '.';
	for (int i = 0; i < buf.size(); i++) {
		vector<string> tmpres(n, str);
		for (int row = 0; row < n; row++) {
			tmpres[row][buf[i][row + 1] - 1] = 'Q';
		}
		res.push_back(tmpres);
	}
	return res;
}
};