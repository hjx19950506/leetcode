/*
直接把数组本身当记录，大于数组长度的和负数不管，其他数字放在和下标相同的位置，找到一个与下表不的即为答案
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 1;
        int i = 0;
        while (i < len) {
            if (nums[i] < len && nums[i] >= 0 && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
            else
                i++;
        }
        i = 1;
        while (i < len && nums[i] == i) {
            i++;
        }
        if (i < len)
            return i;
        else
            return nums[0] == i ? i + 1 : i;
    }
};