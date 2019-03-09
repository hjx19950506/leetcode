/*
水平扫描，一列一列的比较
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int ptr = 0, i = 0;
        int flag = 1;
        if (strs.empty())
            return ans;
        while (ptr < strs[0].length()) {
            i = 0;
            char tmp = strs[0][ptr];
            while (i < strs.size()) {
                if (ptr >= strs[i].length() || strs[i][ptr] != tmp) {
                    flag = 0;
                    break;
                }
                i++;
            }
            if (flag == 1)
                ans += tmp;
            else
                break;
            ptr++;
        }
        return ans;
    }
};