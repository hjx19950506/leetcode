/*
分治，找到最高的，分为两个，再找两个中各自最高的
*/
class Solution {
public:
	int trapDQ(vector<int> &height, int l, int r) {
		while (height[l] == 0) l++;
		while (height[r] == 0) r--;
		if (r - l <= 1)
			return 0;
		int mid = l + 1, max = height[l+1];
		for (int i = mid+1; i < r; i++) {
			if (height[i] > max) {
				mid = i;
				max = height[i];
			}
		}
		if (height[mid] <= height[l] && height[mid] <= height[r]) {
			int lon = min(height[l], height[r]);
			int wid = r - l - 1;
			int mid_sum = 0;
			for (int i = l + 1; i < r; i++)
				mid_sum += height[i];
			return lon * wid - mid_sum;
		}
		else {
			return trapDQ(height, l, mid) + trapDQ(height, mid, r);
		}
		return 0;
	}

	int trap(vector<int>& height) {
		if (height.size() <= 2)
			return 0;
		int  l = 0, r = height.size() - 1;
		return trapDQ(height, l, r);
	}
};