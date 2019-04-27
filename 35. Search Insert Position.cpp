/*
¶þ·Ö
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return 0;
        else if (nums[0] >= target)
            return 0;
        else if (nums[len-1] < target)
            return len;
        int mid;
        int l = 0, r = len - 1;
        while (l <r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) 
                return mid;
            else if (nums[mid] < target && nums[mid+1] >= target)
                return mid+1;
            else if (nums[mid] < target)
                l = mid;
            else
                r = mid;
        }
        return mid;
    }
};