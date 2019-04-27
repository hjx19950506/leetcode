/*
方法一是回溯的方法
方法二是下一个全排列，和上题类似
*/

class Solution {
public:
	void perm(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int cur) {
		if (cur == nums.size()) {
			res.push_back(tmp);
		}
		else {
			for (int i = 0; i < nums.size(); i++) {
				if (i == 0 || nums[i] != nums[i - 1]) {
					int c1 = 0, c2 = 0;
					for (int j = 0; j < nums.size(); j++)
						if (nums[j] == nums[i])
							c1++;
					for (int j = 0; j < cur; j++)
						if (tmp[j] == nums[i])
							c2++;
					if (c1 > c2) {
						tmp[cur] = nums[i];
						perm(nums, res, tmp, cur + 1);
					}

				}
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		int size = nums.size();
		if (size == 0)
			return res;
	    sort(nums.begin(), nums.end());
		vector<int> tmp(size,0);
		perm(nums, res, tmp, 0);
		return res;
	}
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        } while (nextPermutation(nums, 0, n - 1));
        return res;
    }
private:
    bool nextPermutation(vector<int> &v, int left, int right) {
        if (left >= right) {
            return false;
        }
        
        int i, j;
        i = right - 1;
        while (i >= left && v[i] >= v[i + 1]) {
            --i;
        }
        if (i < left) {
            return false;
        }
        
        j = right;
        while (v[i] >= v[j]) {
            --j;
        }
        swap(v[i], v[j]);
        reverse(v.begin() + i + 1, v.begin() + right + 1);
        return true;
    }
};