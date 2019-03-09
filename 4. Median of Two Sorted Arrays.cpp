/*
��ĿҪ��ʱ�临�Ӷ�ΪO(logn)�����ö��ֲ��ҡ�
��ȻҪ����λ������ʵ���ǰ�����������ȷ֣���ȷ��i��ͬʱ��jҲȷ��Ϊ(m+n+1)/2-i��
����ʱ��Ҫ��nums1[i-1] < nums2[j], nums1[i] > nums2[j-1]
*/

class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	if (m > n) {
		vector<int> temp = nums1; nums1 = nums2; nums2 = temp;
		int tmp = m; m = n; n = tmp;
	}
	int iL = 0, iR = m, halfLen = (m + n + 1) / 2;
	while (iL <= iR) {
		int i = (iL + iR) / 2, j = halfLen - i;
		if (i < iR && nums1[i] < nums2[j - 1]) {
			iL = i + 1;
		}
		else if (i > iL && nums2[j] < nums1[i - 1]) {
			iR = i - 1;
		}
		else {
			int maxLeft = 0;
			if (i == 0) maxLeft = nums2[j - 1];
			else if (j == 0) maxLeft = nums1[i - 1];
			else maxLeft = (nums1[i - 1] > nums2[j - 1]) ? nums1[i - 1] : nums2[j - 1];
			if ((m + n) % 2 == 1)
				return maxLeft;


			int minRight = 0;
			if (i == m) minRight = nums2[j];
			else if (j == n) minRight = nums1[i];
			else minRight = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];


			return (double)(maxLeft + minRight) / 2;
		}
	}
	return 0.0;
}
};