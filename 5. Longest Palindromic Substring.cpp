/*
dp 
P(i,j)=(P(i+1,j−1) and Si == Sj) 
*/


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2)
            return s;
        string result = "";
        int **map = new int *[s.length()];
        for (int i = 0; i<s.length(); ++i)
        {
            map[i] = new int[s.length()];
        }

        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i <= j; i++) {
                if (j - i == 0 || (j - i == 1 && s[i] == s[j]))
                    map[i][j] = 1;
                else if (s[i] == s[j])
                    map[i][j] = map[i + 1][j - 1];
                else
                    map[i][j] = 0;
                if (map[i][j] == 1 && j - i + 1 > result.length()) {
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }
};