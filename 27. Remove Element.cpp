/*
����˫ָ�룬ֻ������ָ����ж�������һ����
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        
        int len = nums.size();
        int i = 0, j = 0;
        while (j < len) {
            if (nums[j] == val)
                j++;
            else 
                nums[i++] = nums[j++];
        }
        return i;
    }
};