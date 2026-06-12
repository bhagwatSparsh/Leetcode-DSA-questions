// brute force approach: 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=-1;
        int last=-1;
        for (int i=0;i<n;i++){
            if (nums[i]==target){
                if (first==-1){
                    first=i;
                    last=i;
                    return {first, last};

                }
                
                
                
            }
            
        }
        return {-1,-1};
        
    }
};
// optimal solution using binary search:

class Solution {
public:
    int first_occurrence(vector<int> &nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]==target){
                first=mid;
                high=mid-1;

            }
            else if (nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return first;
    }

    int last_occurrence(vector<int> &nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;


            }
            else{
                high=mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=first_occurrence(nums, target);
        if (first==-1){
            return {-1,-1};

        }
        int last=last_occurrence(nums, target);
        return {first, last};

        
        
    }
};