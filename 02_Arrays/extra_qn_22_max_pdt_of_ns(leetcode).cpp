class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_pdt=0;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int start=i;
                int next=j;
                int pdt=(nums[i]-1)*(nums[j]-1);
                if (pdt>max_pdt){
                    max_pdt=pdt;
                }
            }

        }
        return max_pdt;
        
    }
};

// optimal soln: just find the largest and sec largest:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1; // Old largest becomes second largest
                max1 = num;  // Update largest
            } else if (num > max2) {
                max2 = num;  // Update second largest
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};