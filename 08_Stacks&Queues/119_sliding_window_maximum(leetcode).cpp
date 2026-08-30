// brute force solution:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=k-1;
        vector<int> ans;
        while(right!=n){
            int max_i=INT_MIN;

            for (int i=left;i<=right;i++){
                max_i=max(max_i, nums[i]);
                


            }
            ans.push_back(max_i);
            
            left++;
            right++;


        }
        return ans;
        
    }
};
// optimal soln:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;
        
        for (int i=0;i<n;i++){
            // make space for nums[i];
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            // step-2
            while(!dq.empty() && nums[i]> nums[dq.back()]){
                dq.pop_back();
            }
            // step-3:
            dq.push_back(i);

            if (i>=k-1){
                ans.push_back(nums[dq.front()]); // will always give max element
            }
        }
        return ans;
        
    }
};