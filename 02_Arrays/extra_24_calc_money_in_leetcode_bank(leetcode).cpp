#include <iostream>

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int rem = n % 7;
        int full_weeks_sum = weeks * 28 + 7 * (weeks * (weeks - 1) / 2);
        
        // Sum of remaining days in the last incomplete week
        int start_val = weeks + 1;
        int rem_days_sum = 0;
        for (int i = 0; i < rem; ++i) {
            rem_days_sum += (start_val + i);
        }
        
        return full_weeks_sum + rem_days_sum;
    }
};