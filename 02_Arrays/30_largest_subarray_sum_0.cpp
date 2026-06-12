class Solution {
public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int max_len = 0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum == 0) {
                max_len = i + 1; 
            }
            else if (mpp.find(sum) != mpp.end()) {
                max_len = max(max_len, i - mpp[sum]);
            }
            else {
                mpp[sum] = i;
            }
        }
        
        return max_len;
    }
};
