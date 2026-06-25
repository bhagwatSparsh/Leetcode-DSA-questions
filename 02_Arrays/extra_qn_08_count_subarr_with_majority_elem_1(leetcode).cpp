// brute force:
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int sub_arr_cnt=0;
        for (int i=0;i<n;i++){
            int target_cnt=0;
            for (int j=i;j<n;j++){
                if (nums[j]==target){
                    target_cnt++;


                }
                int len_subarr=j-i+1;
                if (target_cnt>(len_subarr)/2){
                    sub_arr_cnt++;
                }
            }
        }
        return sub_arr_cnt;

        
    }
};

// optimal soln:
