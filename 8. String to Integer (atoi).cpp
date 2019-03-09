/*
注意理解题意即可
*/

class Solution {
public:
    int myAtoi(string str) {
        int p = 0;
        int ans = 0;
        while (p < str.length()) {
            if (str[p] != ' ') {
                break;
            }
            p++;
        }
        if (p == str.length())
            return 0;
        if (str[p] != '+' && str[p] != '-' && !(str[p] >= '0' && str[p] <= '9'))
            return 0;
        int flag = 1;
        if (str[p] == '-') {
            flag = -1;
            p++;    
        }
        else if (str[p] == '+')
            p++;
        while (p < str.length() && (str[p] >= '0' && str[p] <= '9')) {
            if (ans > INT_MAX/10 || (ans == INT_MAX / 10 && str[p] > '7')) return INT_MAX;
            if (ans < INT_MIN/10 || (ans == INT_MIN / 10 && str[p] > '8')) return INT_MIN;
            ans = ans * 10 + flag * (str[p] - '0');
            p++;
        }
        return ans;
    }
};