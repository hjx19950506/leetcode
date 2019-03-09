/*
DFS
*/

class Solution {
public:
    void trans(char c, string *m, string*n, string *p, string *q) {
	*q = '0';
	if (c == '7') { *m = 'p'; *n = 'q'; *p = 'r'; *q = 's'; return;}
	if (c == '8') { *m = 't'; *n = 'u'; *p = 'v'; return;}
	if (c == '9') { *m = 'w'; *n = 'x'; *p = 'y'; *q = 'z'; return;}
	*m = (c - '2') * 3 + 'a';
	*n = (c - '2') * 3 + 'a' + 1;
	*p = (c - '2') * 3 + 'a' + 2;
    }
    vector<string> letterCombinations(string digits) {
        int length = digits.length();
        vector<string> ans, buf;
        int ptr = 0;
        string c1, c2, c3, c4;

        if (length == 0)
            return ans;
        else {
            trans(digits[ptr], &c1, &c2, &c3, &c4);
            ans.push_back(c1);
            ans.push_back(c2);
            ans.push_back(c3);
            if (digits[ptr] == '7' || digits[ptr] == '9')
                ans.push_back(c4);
            ptr++;
        }


        while (ptr < length) {
            trans(digits[ptr], &c1, &c2, &c3, &c4);
            while (!ans.empty()) {
                string tmp = ans.back();
                ans.pop_back();
                buf.push_back(tmp + c1);
                buf.push_back(tmp + c2);
                buf.push_back(tmp + c3);
                if (digits[ptr] == '7' || digits[ptr] == '9')
                    buf.push_back(tmp + c4);
            }
            ans = buf;
            buf.clear();
            ptr++;
        }
        return ans;
    }
};