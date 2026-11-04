// brute force solution:
class Solution {
public:
    bool is_even(char c) {
        return c == '0' || c == '2' || c == '4' || c == '6' || c == '8';
    }

    bool is_prime(char c) {
        return c == '2' || c == '3' || c == '5' || c == '7';
    }

    int countGoodNumbers(long long n) {
        const long long MOD = 1e9 + 7;
        long long ans = 1;

        for (int i = 0; i < n; i++) {
            int valid_choices = 0;

            // Check each possible single digit ('0' through '9') for the current place
            for (char digit = '0'; digit <= '9'; digit++) {
                if (i % 2 == 0) {
                    if (is_even(digit)) {
                        valid_choices++;
                    }
                } else {
                    if (is_prime(digit)) {
                        valid_choices++;
                    }
                }
            }

            ans = (ans * valid_choices) % MOD;
        }

        return ans;
    }
};

// optimal solution:
class Solution {
public:
    const long long m = 1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0) {
            return 1;
        }
        long long half = power(a, b / 2);
        long long res = (half * half) % m;
        if (b % 2 == 1) {
            res = (res * a) % m;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long ans = (power(5, even_count) * power(4, odd_count)) % m;
        return ans;
    }
};