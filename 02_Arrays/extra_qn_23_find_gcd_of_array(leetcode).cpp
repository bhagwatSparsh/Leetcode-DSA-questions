#include <vector>
#include <climits>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        int min = INT_MAX;
        int max = INT_MIN;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        
        for (int i = min; i >= 1; i--) {
            if (min % i == 0 && max % i == 0) {
                return i;
            }
        }
        
        return 1;
    }
};