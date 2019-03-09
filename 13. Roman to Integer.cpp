/*
与上一题差不多，反向思维
*/

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == 'M') {
                if (i == 0 || s[i-1] != 'C') {
                    ans += 1000;
                    i++;
                }
                else if (s[i-1] == 'C'){
                    ans += 800;
                    i++;
                }
            }
            if (s[i] == 'D') {
                if (i == 0 || s[i-1] != 'C') {
                    ans += 500;
                    i++;
                }
                else if (s[i-1] == 'C') {
                    ans += 300;
                    i++;
                }
            }

            
            if (s[i] == 'C') {
                if (i == 0 || s[i-1] != 'X') {
                    ans += 100;
                    i++;
                }
                else if (s[i-1] == 'X') {
                    ans += 80;
                    i++;
                }
            }
            if (s[i] == 'L') {
                if (i == 0 || s[i-1] != 'X') {
                    ans += 50;
                    i++;
                }
                else if (s[i-1] == 'X') {
                    ans += 30;
                    i++;
                }
            }
            
            
            if (s[i] == 'X') {
                if (i == 0 || s[i-1] != 'I') {
                    ans += 10;
                    i++;
                }
                else if (s[i-1] == 'I') {
                    ans += 8;
                    i++;
                }
            }
            if (s[i] == 'V') {
                if (i == 0 || s[i-1] != 'I') {
                    ans += 5;
                    i++;
                }
                else if (s[i-1] == 'I') {
                    ans += 3;
                    i++;
                }
            }
            if (s[i] == 'I') {
                ans++;
                i++;
            }
        }
        return ans;
    }
};