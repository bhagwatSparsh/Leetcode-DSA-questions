// O(N) solution:

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_val=INT_MAX;
        int n=nums.size();
        for (int i=0;i<n;i++){
            if (nums[i]<min_val){
                min_val=nums[i];
            }
        }
        return min_val;
        
        
    }
};

// O(LOGN) solution:

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};