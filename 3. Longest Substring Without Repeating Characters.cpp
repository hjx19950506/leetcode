/*
滑动窗口，双指针pre、last，pre向右滑动，用hash记录遍历过的字母及索引，
同时更新最大长度，遇到重复字母时，将last移至与当前字符重复的上一个字符处
*/

class Solution {
public:
    int Max(int a, int b) {
        if (a > b)
            return a;
        else 
            return b;
    }
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        string st = "";
        int i = 0, j = 0;
        while (i < s.size() && j < s.size()) {
            if (st.find(s[j]) == st.npos) {
                st.insert(st.end(), s[j]);
                j++;
                max = Max(max, st.size());
            }
            else {
                st.erase(st.find(s[i]), 1);
                i++;
            }
            
        }
        return max;
    }
};