class Solution {
public:
    int no_of_students(vector<int> &nums, int pages){
        int cnt=1;
        int n=nums.size();
        long long no_pages=0;
        for (int i=0;i<n;i++){
            if (nums[i]+no_pages<=pages){
                no_pages+=nums[i];
            }
            else{
                cnt++;
                no_pages=nums[i];

            }

        }
        return cnt;

    }
    int findPages(vector<int> &nums, int m)  {
        int n=nums.size();
        if (m>n){
            return -1;
        }
        int max_i=nums[0];
        int sum=0;
        for (int i=0;i<n;i++){
            max_i=max(max_i, nums[i]);
            sum+=nums[i];
        }
        int low=max_i;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if (no_of_students(nums, mid)>m){
                low=mid+1;

            }
            else{
                high=mid-1;
            }
        }
        return low;

        
    }
};