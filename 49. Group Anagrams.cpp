/*
把每个字符串排序后分类即可
*/

class Solution {
public:
string gen(string str) {
	vector<int> buf(26, 0);
	for (int i = 0; i < str.length(); i++) {
		buf[str[i] - 'a']++;
	}
	string res;
	for (int i = 0; i < 26; i++) {
		res += '#';
		char c = buf[i] + '0';
		res += c;
	}
	return res;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int i = 0, size = strs.size();
	vector<vector<string>> res;
	while (i < size) {
		string code = gen(strs[i]);
		if (res.empty()) {
			vector<string> tmp;
			tmp.push_back(code);
			tmp.push_back(strs[0]);
			res.push_back(tmp);
		}
		else {
			int j = 0;
			while (j < res.size()) {
				if (code == res[j][0]) {
					res[j].push_back(strs[i]);
					break;
				}
				j++;
			}
			if (j == res.size()) {
				vector<string> tmp;
				tmp.push_back(code);
				tmp.push_back(strs[i]);
				res.push_back(tmp);
			}
		}
		i++;
	}
	for (int k = 0; k < res.size(); k++) {
		res[k].erase(res[k].begin());
	}
	return res;
}
};