/*
����ջ�����
����(()(())(()
    0111111011
ת����Ѱ�������1������
*/
/*���Ͽ�������DP�ķ���Ҳ����
dp[i]Ϊ��i�������Ч���ţ����s[i]Ϊ�����ţ���dp[i]Ϊ0����Ϊ���ַ������������Ž������򲻿���Ϊ��Ч�ģ�
����Ϊ�����ţ������������
һ����ǰ��s[i-1]Ϊ�����ţ�����dp[i]=dp[i-2]+2;
����s[i-1]Ϊ��������s[i-dp[i-1]-1]Ϊ�����ţ����� dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]��
����i-dp[i-1]-1��Ӧ��Ӧ����ŵ���ʼ��
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