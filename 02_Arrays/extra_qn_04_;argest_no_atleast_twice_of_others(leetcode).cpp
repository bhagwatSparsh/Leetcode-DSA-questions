// brute force soln:
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int max_i=0;
        int idx=0;
        int curr_i=0;
        for (int i=0;i<n;i++){
            curr_i=nums[i];
            if (curr_i>max_i){
                max_i=curr_i;
                idx=i;
            }

        }
        for (int i=0;i<n;i++){
            if (max_i<2*nums[i]){
                return -1;

            }
        }
        return idx;
        
    }
};

// optimal soln:
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // If the largest element is at least twice the second largest element, it is automatically at least twice as large as every other element in the array!
        int n=nums.size();
        int largest=INT_MIN;
        int sec_largest=INT_MIN;
        int idx=-1;
        for (int i=0;i<n;i++){
            if (nums[i]>largest){
                sec_largest=largest;
                largest=nums[i];
                idx=i;
            }
            else if(nums[i]>sec_largest){
                sec_largest=nums[i];
            }
        }
        if (2*sec_largest<=largest){
            return idx;
        }
        return -1;
        
        
    }
};