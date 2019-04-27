/*
硬做的，一位一位乘，保留进位，
个人不是特别喜欢这种题目
*/
class Solution {
public:
string multiply(string num1, string num2) {
	int l1 = num1.length(), l2 = num2.length();
	if (num1[0] == '0' || num2[0] == '0')
		return "0";

	vector<string> buf;
	string res;
	for (int i = l1 - 1; i >= 0; i--) {
		string tmp = "";
		int m = num1[i] - '0';
		int product = 0;
		int carry = 0;
		char unit;
		for (int j = l2 - 1; j >= 0; j--) {
			int n = num2[j] - '0';
			product = m * n + carry;
			unit = product % 10 + '0';
			carry = product / 10;
			tmp.push_back(unit);
		}
		unit = carry + '0';
		tmp.push_back(unit);
		for (int k = 0; k < l1 - 1 - i; k++)
			tmp = '0' + tmp;
		buf.push_back(tmp);
	}
	int size = buf.size();
	int carry = 0;
	int unit = 0;
	for (int i = 0; i <= l2+l1; i++) {
		int sum = carry;

		for (int j = 0; j < size; j++) {
			if (i < buf[j].size())
				sum += buf[j][i] - '0';
		}
		unit = sum % 10;
		carry = sum / 10;
		char tmp = unit + '0';
		res = tmp + res;
	}
	int i = 0;
	while (res[i] == '0')
		res.erase(i, i + 1);
	return res;
}
};