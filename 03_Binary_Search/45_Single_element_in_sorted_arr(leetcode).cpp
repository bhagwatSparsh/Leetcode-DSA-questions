// brute force: O(N) solution:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        
        for (int i = 0; i < n; i += 2) {
           
            if ( i==n-1 || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return -1; 
    }
};

// optimal O(logN) solution using binary search:

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        // trimming down search spaces by checking individually for first and last element.
        //(to avoid edge cases)
        if (n==1){
            return nums[0];
        }
        if (nums[0]!=nums[1]){
            return nums[0];
        }
        if (nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }

        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if ((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }
        return -1;


        
    }
};