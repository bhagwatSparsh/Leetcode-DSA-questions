class Solution {
public:
    int square_dig(int n) {
        int sum = 0; 
        while (n != 0) {
            int dig = n % 10;
            sum += dig * dig;
            n = n / 10;
        }
        return sum; 
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = square_dig(n);
        while (fast != 1 && slow != fast) {
            slow = square_dig(slow);              
            fast = square_dig(square_dig(fast));   
        }

        return fast == 1;
    }
};