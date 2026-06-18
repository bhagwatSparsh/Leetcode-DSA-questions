class Solution {
public:
    int is_possible(vector<int> &nums, int max_possible_sum){
        int n=nums.size();
        int cnt=1;
        int no_subarr=0;
        for (int i=0;i<n;i++){
            if (nums[i]+no_subarr<=max_possible_sum){
                no_subarr+=nums[i];
                
            }
            else{
                cnt++;
                no_subarr=nums[i];

            }
        }
        return cnt;


    }
    int splitArray(vector<int>& nums, int k) {
        int max_i=0;
        int n=nums.size();
        int sum=0;
        if (k>n){
            return -1;
        }
        for (int i=0;i<n;i++){
            max_i=max(max_i, nums[i]);
            sum+=nums[i];

        }
        int low=max_i;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if (is_possible(nums, mid)>k){
                low=mid+1;



            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};