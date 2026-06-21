// brute force soln:
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            nums[i]=(long long)nums[i]*nums[i];


        }
        sort(nums.begin(), nums.end());
        return nums;
        
    }
};
// optimal soln:
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // optimal approach using two pointer:

        int n=nums.size();
        int left=0;
        int right=n-1;
        int idx=n-1;// start adding from last index;
        vector<int> res(n);
        while(left<=right){
            int left_sq=nums[left]*nums[left];
            int right_sq=nums[right]*nums[right];

            if (left_sq>right_sq){
                res[idx]=left_sq;
                left++;

            }
            else{
                res[idx]=right_sq;
                right--;
            }
            idx--; // reduce the value of index at every step as one place is allocated now;
        }
        return res;
        
    }
};