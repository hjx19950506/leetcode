class Solution {
/*
双指针分别指向头尾，将两段较短的一处向内移动，时刻记录最大值
*/


public:
    int Min(int a, int b) {
        if (a < b)
            return a;
        else
            return b;
    }
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int tmp = (right - left) * Min(height[left], height[right]);
            if (tmp > ans)
                ans = tmp;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};