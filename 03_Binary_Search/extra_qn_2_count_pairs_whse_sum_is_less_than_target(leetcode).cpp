class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int cnt=0;
        sort(nums.begin(), nums.end());
        int low=0;
        int n=nums.size();
        int high=n-1;

        while(low<high){
            if (nums[low]+ nums[high]<  target){
                cnt+=(high-low);
                low++;

            }
            else{
                high--;
            }
        }
        return cnt;
        
    }
};