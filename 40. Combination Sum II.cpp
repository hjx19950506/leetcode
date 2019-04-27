/*
����һ�����ƣ�������Ϊ�����ظ�ʹ�����֣������ڽ���һ��combʱstartҪ+1
*/

class Solution {
public:
void comb(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& tmp, int start) {
	if (target == 0)
		res.push_back(tmp);
	else {
		int i = start;
		while (i < candidates.size() && candidates[i] <= target) {
			tmp.push_back(candidates[i]);
			comb(candidates, target - candidates[i], res, tmp, i+1);
			tmp.pop_back();
			i++;
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	vector<int> tmp;
	int len = candidates.size();
	if (len) {
		comb(candidates, target, res, tmp, 0);
	}
    sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}
};