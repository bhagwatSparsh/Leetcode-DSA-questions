class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_val=nums.back();

        vector<int> arr(max_val+2,0);
        int ans=0;
        for (int x:nums){
            arr[x+1]=arr[x]+1;
            arr[x]=arr[x-1]+1;
            ans=max({ans,arr[x],arr[x+1]});
        }
        return ans;


        
        
        
    }
};