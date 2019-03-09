/*
��������֮�͵ķ�ʽ���ƣ�ʱ�̸���
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestNum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r){
                int threeSum = nums[l] + nums[r] + nums[i];
                if (fabs(threeSum - target) < fabs(closestNum - target)) {
                    closestNum = threeSum;
                }
                if (threeSum > target) {
                    r--;
                } else if (threeSum < target) {
                    l++;
                } else {
                    // ����Ѿ�����target�Ļ�, �϶�����ӽ���
                    return target;
                }

            }

        }

        return closestNum;
    }
};