/*
先排序，然后依次选定一个数，对其后的数据使用两数之和的方法
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> S;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            /*if (i > 0 && nums[i] == nums[i-1]) {
                i++;
                continue;
            }*/
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                vector<int> tmp;
                if (nums[i] + nums[j] + nums[k] == 0) {
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    S.insert(tmp);
                    /*do {*/
                        j++;
                    /*}while (nums[j] == nums[j+1]);
                    do {*/
                        k--;
                   /* }while (nums[k] == nums[k-1]);*/
                }
                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
            }
        }
        vector<vector<int>> ans(S.begin(), S.end());
        return ans;
    }
};