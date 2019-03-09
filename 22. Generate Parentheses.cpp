/*
»ØËİ
*/

class Solution {
public:
    void generator(vector<string> &vec, int left, int right,string s) {
        if (left == 0 && right == 0) {
            vec.push_back(s);
        }
        if (left > 0) {
            generator(vec, left-1, right, s+'(');
        }
        if (right > 0 && right > left) {
            generator(vec, left, right-1, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generator(result, n, n, s);
        return result;
    }
};