//Brute solution:

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n=nums.size();

        int max_len=0;
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                int sum=0;
                for (int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                if (sum==k){
                    max_len=max(max_len, j-i+1);
                }
            }

        }
        return max_len;
        
    }
};


//Optimal soln:

// Two pointer approach: 
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n=nums.size();

        int left=0;
        int right=0;
        int sum=nums[0];
        int max_len=0;
        while(right<n){
            while(left<=right && sum>k){
                sum=sum-nums[left];
                left++;
            }
            if (sum==k){
                max_len=max(max_len,right-left+1);
            }
            right++;
            if(right<n){
                sum+=nums[right];
            }

        }
        return max_len;
        
    }
};

