class Solution {
public:
    int smallestNumber(int n, int t) {
       
        for (int i = n; i <= n + 10; i++) {
            int temp = i; 
            int pdt = 1;

            while (temp != 0) {
                int dig = temp % 10;
                pdt *= dig;
                temp /= 10;
            }

            if (pdt % t == 0) {
                return i;
            }
        }
        return -1;
    }
};