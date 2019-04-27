/*
ֱ�Ӱ����鱾����¼���������鳤�ȵĺ͸������ܣ��������ַ��ں��±���ͬ��λ�ã��ҵ�һ�����±��ļ�Ϊ��
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