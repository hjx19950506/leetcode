/*
����˼ά����ÿ�����ֶ���������������֣������߽���Ƿ�Ϊtarget�������ַ���ʱ�临�Ӷȴﵽ��O(n^2)
����˼ά���ù�ϣ����ÿ������������������ÿ�����֣���������û��target-nums[i]
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