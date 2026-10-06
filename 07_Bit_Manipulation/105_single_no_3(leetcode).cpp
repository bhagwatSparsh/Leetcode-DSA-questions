// brute force soln: using hashmap:

// usage of const auto& p : mpp- can also use pai<int, int> p : mpp to solve this problem
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n=nums.size();
        for (int i=0;i<n;i++){
            mpp[nums[i]]++;

        }
        vector<int> ans;
        for (const auto& p : mpp){
            if (p.second==1){
                ans.push_back(p.first);
            }
        }
        return ans;
        
    }
};

