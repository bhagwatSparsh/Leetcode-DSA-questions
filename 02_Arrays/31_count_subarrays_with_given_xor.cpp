class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n=nums.size();
        int xr=0;
        int cnt=0;
        unordered_map<int,int> mpp;
        mpp[xr]++;
        for (int i=0;i<n;i++){
            xr=xr^nums[i];
            int x=xr^k;
            cnt+=mpp[x];
            mpp[xr]++;

        }
        return cnt;

        
    }
};
