/*
˫ָ�룬һ����ǰ��ʶ��ǰ��������ĩβ��һ���ں��ʶ��⵽�������֣�
��⵽������ʱ��ǰ����
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