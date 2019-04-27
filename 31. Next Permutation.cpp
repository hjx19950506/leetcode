/*
从右边找到第一对两个连续的数字a[i]和 a[i-1]a[i−1]，它们满足a[i]>a[i-1]。
对a[i−1]右侧的重新排列可以创建更大的排列，因为该子数组由数字按降序组成。
因此，我们需要重新排列a[i-1]右边的数字，包括它自己。
将数字a[i-1]替换为位于其右侧区域的数字中比它更大的数字a[j]。
交换数字a[i−1]和a[j]。但目前的排列仍然不是我们正在寻找的排列。
需要使a[i−1]右边的数字来形成最小的排列。
*/
//利用康拓展开和逆展开的做法更加简洁


class Solution {
public:
    void swap(int &i, int &j) {
	int tmp = i;
	i = j;
	j = tmp;
	return;
    }
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1)
            return;
        int p = len - 1;
        while (p > 0) {
            if (nums[p] > nums[p - 1])
                break;
            p--;
        }
        if (p == 0) {
            int i = 0, j = len - 1;
            while (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            return;
        }
        vector<int> tmp;
        for (int i = p - 1; i < len; i++) {
            tmp.push_back(nums[i]);
        }
        sort(tmp.begin(), tmp.end());
        int index = find_if(tmp.begin(), tmp.end(), bind2nd(greater<int>(), nums[p - 1])) - tmp.begin();
        nums[p - 1] = tmp[index];
        tmp.erase(index + tmp.begin());
        if (!tmp.empty()) {
            int k = 0;
            for (int i = p; i < len; i++) {
                nums[i] = tmp[k];
                k++;
            }
        }
        return;
    }
};