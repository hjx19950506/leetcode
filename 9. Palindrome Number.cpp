/*
�����ֱ���ĺ�һ�뷴ת��Ȼ�󽫷�ת���������ǰһ�����ֽ��бȽϣ������������ͬ�ģ���ô������־��ǻ��ġ�
Ҫע���㵽x��resСʱ��˵�������ˡ�
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return 0;
        int res = 0;
        while (x > res) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return x == res || x == res / 10;
    }
};