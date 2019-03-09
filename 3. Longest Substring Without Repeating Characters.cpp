/*
�������ڣ�˫ָ��pre��last��pre���һ�������hash��¼����������ĸ��������
ͬʱ������󳤶ȣ������ظ���ĸʱ����last�����뵱ǰ�ַ��ظ�����һ���ַ���
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