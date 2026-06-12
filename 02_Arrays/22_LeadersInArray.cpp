// brute solution:

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for (int i=0;i<n;i++){
            bool leader=true;
            for (int j=i+1;j<n;j++){
                if (nums[j]>nums[i]){
                    leader=false;
                    
                }
            }
            if (leader==true){
                ans.push_back(nums[i]);
            }

        }
        return ans;
      
    }
};

//optimal solution:

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int maxi=INT_MIN;
        for (int i=n-1;i>=0;i--){
            if (nums[i]>maxi){
                ans.push_back(nums[i]);
                
            }
            maxi=max(maxi,nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
      
    }
};
