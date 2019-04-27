/*
方法一核心是交换
方法二核心是额外数组用来标记
方法三是一种与前俩种方法思路不同的方法，next_permutation，31题的思路
*/

class Solution {
public:
	void perm(vector<int>& nums, vector<vector<int>> &res, int start, int end) {
		if (start == end)
			res.push_back(nums);
		else {
			for (int i = start; i <= end; i++) {
				swap(nums[i], nums[start]);
				perm(nums, res, start + 1, end);
				swap(nums[i], nums[start]);
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		int size = nums.size();
		if (size == 0)
			return res;
		
		perm(nums, res, 0, size-1);
		return res;
	}
};


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sz = nums.size();
		for (int i = 0; i < sz; i++)
			flag.push_back(1);
		dfs(nums, 0);
		return res;
	}

	void dfs(vector<int>& nums,int n) {
		if (n == sz)
			res.push_back(tmp);
		else {
			for (int i = 0; i < sz; i++) {
				if (flag[i] == 1) {
					flag[i] = 0;
					tmp.push_back(nums[i]);
					dfs(nums, n + 1);
					flag[i] = 1;
					tmp.pop_back();
				}
			}
		}
	}
private:
	vector<vector<int>> res;
	vector<int> flag;
	vector<int> tmp;
	int sz = 0;
};


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int n = nums.size();
		int fac = 1;
		int i;
		for (i = 1; i <= n; ++i) {
			fac *= i;
		}
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());
		for (i = 0; i < fac; ++i) {
			res.push_back(nums);
			next_permutation(nums, 0, n - 1);
		}
		return res;
	}
private:
	void next_permutation(vector<int> & v, int left, int right) {
		if (left >= right) {
			return;
		}
		int i = right - 1;
		while (i >= left && v[i] >= v[i + 1]) {
			--i;
		}
		if (i < left) {
			reverse(v.begin() + left, v.begin() + right + 1);
			return;
		}
		int j = right;
		while (j >= left && v[j] <= v[i]) {
			--j;
		}
		swap(v[i], v[j]);
		reverse(v.begin() + i + 1, v.begin() + right + 1);
	}
};