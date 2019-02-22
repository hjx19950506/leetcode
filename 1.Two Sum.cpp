/*
正常思维，对每个数字都遍历其后所有数字，看两者结果是否为target，但这种方法时间复杂度达到了O(n^2)
逆向思维，用哈希表保存每个数及其索引，遍历每个数字，看表中有没有target-nums[i]
*/
#include <vector>
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int ,int> m;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) == m.end())
                m[nums[i]] = i;
            else {
                result = {m[target - nums[i]], i};
                break;
            }
        }
        return result;
        
    }
};