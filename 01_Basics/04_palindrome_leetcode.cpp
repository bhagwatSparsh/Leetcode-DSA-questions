class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int original = x;
        int rev = 0;

        while (x > 0) {
            int digit = x % 10;

            if (rev > (INT_MAX) / 10) {
                return false; 
            }

            rev = rev * 10 + digit;
            x = x / 10;
        }

        return rev == original;
    }
};

