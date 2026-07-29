class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle 32-bit integer overflow edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        if (dividend == divisor) {
            return 1;
        }

        bool sign = true; // +ve integer
        if (dividend >= 0 && divisor < 0) {
            sign = false;
        }
        if (dividend <= 0 && divisor > 0) {
            sign = false;
        }
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;

        while (n >= d) { // till denom is less than or equal to numr
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            
            ans += (1LL << cnt); 
            n = n - (d << cnt);
        }
        if (ans >= INT_MAX && sign == true) {
            return INT_MAX;
        }
        if (ans > INT_MAX && sign == false) {
            return INT_MIN;
        }

        if (sign == true) {
            return ans;
        }
        return -ans;
    }
};