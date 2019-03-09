/*
���ö�ջ������ջ�������Ҫ���ջ���Ƿ�Ϊ��
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int ptr = 0;
        char tmp;
        while (ptr < s.length()) {
            if (s[ptr] == '(' || s[ptr] == '[' || s[ptr] == '{')
                st.push(s[ptr]);
            else {
                if (st.empty() || (s[ptr] == ')' && st.top() != '('))
                    return false;
                else if (st.empty() || (s[ptr] == ']' && st.top() != '['))
                    return false;
                else if (st.empty() || (s[ptr] == '}' && st.top() != '{'))
                    return false;
                st.pop();
            }
            ptr++;
        }
        return st.empty() ? true : false;
    }
};