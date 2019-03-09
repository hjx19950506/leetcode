/*
双指针，一个在前标识当前有序数列末尾，一个在后标识检测到的新数字，
检测到新数字时向前覆盖
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        int i = 0, j = 1;
        while (j < len) {
            while (j < len && nums[j] == nums[j-1]) {
                j++;
            }
            if (j < len)
                nums[++i] = nums[j++];
        }
        return i+1;
    }
};