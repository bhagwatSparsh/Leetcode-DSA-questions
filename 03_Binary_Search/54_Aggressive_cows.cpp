class Solution {
public:
    bool can_we_place(vector<int> &nums, int k, int distance){
        int n=nums.size();
        int cnt=1;
        
        last=nums[0];
        for (int i=1;i<n;i++){
            if (nums[i]-last>=distance){
                last=nums[i];
                cnt++;

            }
        }
        if (cnt>=k){
            return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());// so that we can get the first and last element as min and max, to get max distn
        int low=1;
        int high=nums[n-1]-nums[0]; // range of the cows(max-min) as this is max distance btw any two cows.
        while(low<=high){
            int mid=(low+high)/2;
            if (can_we_place(nums,k,mid)==true){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;


        
    }
};