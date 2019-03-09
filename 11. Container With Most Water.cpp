class Solution {
/*
˫ָ��ֱ�ָ��ͷβ�������ν϶̵�һ�������ƶ���ʱ�̼�¼���ֵ
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