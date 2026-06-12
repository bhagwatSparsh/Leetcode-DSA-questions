// better soln:

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        
        int cnt=0;
        for (int i=0;i<n;i++){
            int sum=0;
            for (int j=i;j<n;j++){
                sum+=nums[j];
                if (sum==k){
                    cnt++;
                    
                    
                }
                
            }
        }
        return cnt;
        
    }
};

//optimal case:

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int pre_sum=0, cnt=0;
        for (int i=0;i<n;i++){
            pre_sum+=nums[i];
            int remove=pre_sum-k;
            cnt+=mpp[remove];
            mpp[pre_sum]+=1;

        }
        return cnt;

        
    }
};