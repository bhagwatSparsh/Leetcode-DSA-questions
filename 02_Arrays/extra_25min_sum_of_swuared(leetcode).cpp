#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        // Find maximum possible difference to bound bucket size
        int max_diff = 0;
        for (int i = 0; i < n; ++i) {
            max_diff = max(max_diff, abs(nums1[i] - nums2[i]));
        }
        
        // count[d] stores how many pairs have absolute difference d
        vector<int> count(max_diff + 1, 0);
        for (int i = 0; i < n; ++i) {
            count[abs(nums1[i] - nums2[i])]++;
        }
        
        // Greedily reduce the largest differences downwards
        for (int d = max_diff; d > 0 && k > 0; --d) {
            if (count[d] == 0) continue;
            
            // If we have enough operations to reduce all elements of value d to d - 1
            if (k >= count[d]) {
                k -= count[d];
                count[d - 1] += count[d];
                count[d] = 0;
            } else {
                // Otherwise, reduce as many as we can by 1
                count[d] -= k;
                count[d - 1] += k;
                k = 0;
            }
        }
        
        // Compute the final sum of squared differences
        long long ans = 0;
        for (long long d = 1; d <= max_diff; ++d) {
            if (count[d] > 0) {
                ans += (long long)count[d] * d * d;
            }
        }
        
        return ans;
    }
};