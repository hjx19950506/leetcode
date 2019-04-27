/*
�ò�ͬ��Լ����д�������ֲ��ҷֱ��ҵ����ұ߽�
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        int pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (pos == n || nums[pos] > target) {
            return res;
        }
        res[0] = pos;
        res[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return res;
    }
};


class Solution {
public:
int left_bound(std::vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size()-1;
	while (begin <= end ) {
		int mid = (begin + end) / 2;
		if (nums[mid] == target) {
			if (nums[mid - 1] < target || mid == 0) {
				return mid;
			}
			//��nums[mid - 1] == target ��˵����ʱ���ҵ���mid��������ߵ�һ��
			//����������[begin,mid-1]��Ȼ���ҵ���һ�����ֵ�
			end = mid - 1;
		}
		else if (target >nums[mid]) {
			begin = mid + 1;
		}
		else if (target <nums[mid]) {
			end = mid - 1;
		}
	}
		return -1;
}

int right_bound(std::vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1; 
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (nums[mid] == target) {
			if (nums[mid + 1] > target || mid == nums.size() - 1) {
				return mid;
			}
			//��nums[mid + 1] == target ��˵����ʱ���ҵ���mid�������ұ����һ��
			//����������[mid+ 1 ,end]��Ȼ���ҵ���һ�����ֵ�
			begin = mid + 1;
		}
	else if (target >nums[mid]) {
			begin = mid + 1;
		}
		else if (target <nums[mid]) {
			end = mid - 1;
		}
	}
	return -1;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
       range.push_back( left_bound(  nums,   target));
         range.push_back( right_bound(  nums,   target));
        return range;
    }
};