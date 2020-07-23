//LeetCode, Pow(x, n)
// 二分法， $ x^n = x^{n/2} * x^{n/2} * x^{n\%2} $
// 時間複雜度 O(logn)，空間複雜度 O(1)
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) 
            return 1.0 / power(x, -n);
        else 
            return power(x, n);
        }
private:
    double power(double x, int n) {
        if (n == 0) 
            return 1;
        double v = power(x, n / 2);
        if (n % 2 == 0) 
            return v * v;
        else 
            return v * v * x;
    }
};