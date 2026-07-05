class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        
        for (int num : nums) {
            string s = to_string(num);// convert to string and then process.
            for (char c : s) {
                ans.push_back(c - '0'); // conv back to integer digit by digit
            }
        }
        
        return ans;
    }
};