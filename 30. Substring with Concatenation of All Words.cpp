/*
������һ��ˢǰ100ʱû�����������𰸶�û���ɣ���Ҫ��û�˽��ϣ��
�ع�ͷ����ʱ���֣�VS��ʵ����unordered_mapʱ�����ù�ϣʵ�ֵģ��������һ���Ӿͼ��ˡ�
�Ȱ�words�ù�ϣ��ã�Ȼ���s��0��ʼ������ÿ����words[0].length()�ĳ��ȣ�
���α����з����Ҳ���words�еĵ��ʻ��߶��˵Ļ���break��
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