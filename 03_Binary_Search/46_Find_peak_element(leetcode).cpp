// brute solution: O(N) solution:

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if (n==1 || nums[0]>nums[1]){
            return 0;
        }
        if (nums[n-1]>nums[n-2]){
            return n-1;
        }

        for (int i=1;i<n-1;i++){
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
        }
        return -1;


        
    }
};

// optimal O(logN) solution using binary search:    
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        // checking for 1st and last element peaks individually to trim down search space;
        if (n==1 || nums[0]>nums[1]){
            return 0;
        }
        if (nums[n-1]>nums[n-2]){
            return n-1;
        }

        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if (nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;

        
    }
};