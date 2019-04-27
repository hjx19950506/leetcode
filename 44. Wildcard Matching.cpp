/*
经典的DP题目
网上看到有人用回溯做，有大概思路，不过好像得用到剪枝，暂时还没学
*/

class Solution {
public:
bool isMatch(string s, string p) {
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= n; i++)
		if (p[i - 1] == '*')
			dp[0][i] = dp[0][i - 1];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*')
				dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
			else {
				dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);

			}
		}
	}
	return dp[m][n];
}
};