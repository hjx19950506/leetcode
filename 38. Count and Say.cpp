/*
没什么特别的算法，在一个vector里存第一个数“1”，之后就对上一个数字做报数
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