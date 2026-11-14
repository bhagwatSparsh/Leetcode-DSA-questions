// uses concept of sliding window
// i have  included this in this folder bcz sliding window is not yet created:

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int min_sum=INT_MAX;

        for (int len=l;len<=r;len++){
            int curr_sum=0;

            for (int i=0;i<len;i++){
                curr_sum+=nums[i];


            }
            if (curr_sum > 0){
                min_sum=min(min_sum, curr_sum);

            }

            for (int i=len;i<n;i++){
                curr_sum+=nums[i]-nums[i-len];
                if(curr_sum>0){
                    min_sum=min(curr_sum, min_sum);

                }

            }

        }
        if (min_sum==INT_MAX){
            return -1;
        }
        return min_sum;
    }
};