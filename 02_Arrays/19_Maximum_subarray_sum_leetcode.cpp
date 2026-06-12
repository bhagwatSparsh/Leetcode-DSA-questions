//better solution:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=INT_MIN;
        for (int i=0;i<n;i++){
            int sum=0;
            
            for (int j=i;j<n;j++){
                sum+=nums[j];
                max_sum=max(sum,max_sum);

            }
            
        }
        return max_sum;
        
    }
};

//optimal solution using Kadane's algorithm:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        long long maxi=LONG_MIN;
        for (int i=0;i<n;i++){
            sum+=nums[i];
            if (sum>maxi){
                maxi=sum;
            }
            if (sum<0){
                sum=0;
            }

        }
        return maxi;
        
    }
};