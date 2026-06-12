// 136. Single Number
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int zorr=0;
        for (int i=0;i<n;i++){
            zorr=zorr^nums[i];
        }
        return zorr;
        
        
    }
};