/*
ûʲô�ر���㷨����һ��vector����һ������1����֮��Ͷ���һ������������
*/

class Solution {
public:
    string countAndSay(int n) {
            vector<string> nums;
            nums.push_back("1");
            int i = 1;
            while (i < n) {
                string last = nums[i - 1];
                string tmp;
                char c;
                int p = 0, q = 0, cnt = 0;
                while (q < last.length()) {
                    if (last[p] == last[q]) {
                        cnt++;
                        q++;
                    }
                    else {
                        c = cnt + '0';
                        tmp += c;
                        tmp += last[p];
                        p = q;
                        cnt = 0;
                    }

                }
                c = cnt + '0';
                tmp += c;
                tmp += last[p];
                nums.push_back(tmp);
                i++;
            }
            return nums[i - 1];
    }
};