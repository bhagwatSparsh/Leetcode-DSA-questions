class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int countTarget = 0;
        int countLess = 0;
        for (int num : nums) {
            if (num < target) {
                countLess++;
            } else if (num == target) {
                countTarget++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < countTarget; ++i) {
            ans.push_back(countLess + i);
        }
        
        return ans;
    }
};