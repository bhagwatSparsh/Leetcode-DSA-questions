// 268. Missing Number



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1)/2;
        int sum_new=0;
        for (int i=0;i<n;i++){
            sum_new+=nums[i];
        }
        return (sum-sum_new);

        
    }
};