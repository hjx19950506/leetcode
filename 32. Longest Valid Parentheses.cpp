/*
利用栈来标记
例：(()(())(()
    0111111011
转换成寻找最长连续1的问题
*/
/*网上看到利用DP的方法也不错
dp[i]为到i处最长的有效括号，如果s[i]为左括号，则dp[i]为0，因为若字符串是以左括号结束，则不可能为有效的；
若是为右括号，有两种情况：
一：其前者s[i-1]为左括号，所以dp[i]=dp[i-2]+2;
二、s[i-1]为右括号且s[i-dp[i-1]-1]为左括号，所以 dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]，
其中i-dp[i-1]-1对应对应最长括号的起始点
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len == 0 || len == 1)
            return 0;
        stack<char> par;
        stack<int> num;
        vector<int> flag(len, 0);
        int p = 0;
        while (p < len) {
            if (s[p] == '(') {
                par.push(s[p]);
                num.push(p);
            }
            else {
                if (!par.empty() && par.top() == '(') {
                    flag[num.top()] = 1;
                    num.pop();
                    flag[p] = 1;
                    par.pop();
                }
                else {
                    par.push(s[p]);
                    num.push(p);
                }
            }
            p++;
        }
        p = 0;
        int max = 0, tmp = 0;
        while (p < len) {
            if (flag[p] == 1) {
                tmp++;
                if (tmp > max)
                    max = tmp;
            }
            else {
                if (tmp > max)
                    max = tmp;
                tmp = 0;
            }
            p++;
        }
        return max;
    }
};