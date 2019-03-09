/*
将数字本身的后一半反转，然后将反转后的数字与前一半数字进行比较，如果它们是相同的，那么这个数字就是回文。
要注意算到x比res小时，说明过半了。
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