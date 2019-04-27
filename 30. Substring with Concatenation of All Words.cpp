/*
这道题第一次刷前100时没做出来，看答案都没做成，主要是没了解哈希。
回过头整理时发现，VS其实在做unordered_map时就是用哈希实现的，那这道题一下子就简单了。
先把words用哈希存好，然后从s的0开始遍历，每次跳words[0].length()的长度，
本次遍历中发现找不到words中的单词或者多了的话就break。
*/


vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> res;
	if (s.empty() || words.empty()) return res;
	int n = words.size(), m = words[0].size();
	unordered_map<string, int> m1;
	for (auto& a : words) ++m1[a];
	for (int i = 0; i <= (int)s.size() - n * m; ++i) {
		unordered_map<string, int> m2;
		int j = 0;
		for (j = 0; j < n; ++j) {
			string t = s.substr(i + j * m, m);
			if (m1.find(t) == m1.end()) break;
			++m2[t];
			if (m2[t] > m1[t]) break;
		}
		if (j == n) res.push_back(i);
	}
	return res;
}