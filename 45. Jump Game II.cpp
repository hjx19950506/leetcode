/*
������̰���㷨���۹���΢��ԶһЩ����μ��´�Ҫ������ԶЩ
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int tmp = 0, cur = 0, steps = 0, f = 0;
        while (cur < size-1) {
            int max = 0;
            for (int i = cur + 1; i <= cur + nums[cur] && i < size; i++) {
                if (i == size - 1) {
                    f = i;
                    break;
                }
                
                int tmp = i + nums[i];
                if (tmp > max) {
                    max = tmp;
                    f = i;
                }
            }
            cur = f;
            steps++;
        }
        return steps;
    }
};