/*
先二分查找到旋转处，再俩部分二分查找；
或者直接二分，一部分一定有序继续二分，另一部分无序的二分成有序和无序，再继续重复之前的步骤。
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        int offset = findPivot(nums);
        int ll, mm, rr;
        
        ll = offset;
        rr = offset + n - 1;
        while (ll <= rr) {
            mm = ll + (rr - ll >> 1);
            if (target < nums[mm % n]) {
                rr = mm - 1;
            } else if (target > nums[mm % n]) {
                ll = mm + 1;
            } else {
                return mm % n;
            }
        }
        return -1;
    }
private:
    int findPivot(vector<int> &nums) {
        int n = nums.size();
        if (n < 2 || nums[0] < nums[n - 1]) {
            return 0;
        }
        int ll, mm, rr;
        
        ll = 0;
        rr = n - 1;
        while (rr - ll > 1) {
            if (nums[ll] == nums[rr]) {
                ++ll;
                continue;
            }
            mm = ll + (rr - ll >> 1);
            if (nums[mm] >= nums[ll]) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        return rr;
    }
};




class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if(nums.size() == 0) return -1;
        if(nums[l] <= nums[r]) return func(l, r, nums, target);
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] > nums[r]){
                if(target <= nums[mid] && target >= nums[l]){
                    return func(l, mid, nums, target);
                }else{
                    l = mid + 1;
                }
            }else{
                if(target <= nums[r] && target >= nums[mid]){
                    return func(mid, r, nums, target);
                }else{
                    r = mid - 1;
                }
            }
        }
        if(nums[r] == target) return r;
        if(nums[l] == target) return l;
        return -1;
    }
    
    int func(int l, int r, vector<int>& nums, int target){
        int idx = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                idx = mid;
                break;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        if(nums[r] == target) return r;
        if(nums[l] == target) return l;
        return idx;
    }
};