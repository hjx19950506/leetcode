/*
KMP
*/

class Solution {
public:
    vector<int> prefix_table(string needle) {
        vector<int> prefix(needle.length());
        prefix[0] = 0;
        int len = 0;
        int i = 1;
        while (i < needle.length()) {
            if (needle[i] == needle[len]) {
                len++;
                prefix[i] = len;
                i++;
            }
            else {
                if (len > 0)
                    len = prefix[len - 1];
                else {
                    prefix[i] = 0;
                    i++;
                }
            }
        }
        for (int i = needle.length()-1; i > 0; i--)
            prefix[i] = prefix[i-1];
        prefix[0] = -1;
        return prefix;
    }
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int m = haystack.length(), n = needle.length();
        if (needle == "")
            return 0;
        else if (haystack == "")
            return -1;
        vector<int> prefix = prefix_table(needle);
        while (i < m) {
            if (j == n-1 && haystack[i] == needle[j])
                return i-j;
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = prefix[j];
                if (j == -1) {
                    i++;
                    j++;
                }
                    
            }
        }
        return -1;
    }
};