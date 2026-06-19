class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n <= 0) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        // if it was perfect power of 2 , n would have reduced down to 1;
        return n == 1;
    }
};