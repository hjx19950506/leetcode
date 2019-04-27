/*
¿ìËÙÃİ
a^(11) = a^(2^0+2^1+2^3)
*/

class Solution {
public:
double myPow(double x, long n) {
	if (x == 1 || n == 0)
		return 1;
	if (n < 0)
		return 1/myPow(x, -n);
	double ans = 1, base = x;
	while (n != 0) {
		if (n & 1 == 1)
			ans *= base;
		base *= base;
		n >>= 1;
	}
	return ans;
}
    
    double myPow(double x, int n) {
        return myPow(x, (long)n);
    }
};