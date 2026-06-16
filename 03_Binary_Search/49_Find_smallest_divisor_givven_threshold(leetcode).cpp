// brute force approach:
class Solution {
public:
    int max_ele(vector<int>& nums) {
        int max_i = 0;
        for (int x : nums) {
            max_i = max(max_i, x);
        }
        return max_i;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_val = max_ele(nums);

        for (int divisor = 1; divisor <= max_val; divisor++) {
            long long sum = 0;

            for (int j = 0; j < nums.size(); j++) {
                sum += ceil((double)nums[j] / divisor);
            }

            if (sum <= threshold) {
                return divisor;
            }
        }

        return max_val;
    }
};

// optimal solution using binary search:
class Solution {
public:
    int max_ele(vector<int>& nums){
        int max_i=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            max_i=max(max_i, nums[i]);
        }
        return max_i;


    }
    long long sum_of_div(vector<int>& nums, int mid){
        long long sum=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max_val=max_ele(nums);
        int low=1;
        int high=max_val;
        
        while(low<=high){
            int mid=(low+high)/2;
            if (sum_of_div(nums,mid)<=threshold){
                high=mid-1;

            }
            else{
                low=mid+1;

            }
            
        }
        return low;
        
    }
};