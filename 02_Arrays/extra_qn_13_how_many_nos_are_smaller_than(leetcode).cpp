//  brute force:
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for (int i=0;i<n;i++){
            int cnt=0;
            for (int j=0;j<n;j++){
                if (i!=j && nums[j]<nums[i]){
                    cnt++;
                }
                

            }
            ans.push_back(cnt);

        }
        return ans;
        
    }
};
// optimal solution:
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums; 
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<int> ans;
       
        unordered_map<int, int> mpp; 
        
        for (int i = 0; i < n; i++) {
            if (mpp.find(sorted_nums[i]) == mpp.end()) {
                mpp[sorted_nums[i]] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(mpp[nums[i]]);
        }

        return ans; 
    }
};

// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int> ans;
//         int n=nums.size();
//         for (int i=0;i<n;i++){
//             int cnt=0;
//             for (int j=0;j<n;j++){
//                 if (i!=j && nums[j]<nums[i]){
//                     cnt++;
//                 }
                

//             }
//             ans.push_back(cnt);

//         }
//         return ans;
        
//     }
// };