// brute force:
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int sub_arr_cnt=0;
        for (int i=0;i<n;i++){
            int target_cnt=0;
            for (int j=i;j<n;j++){
                if (nums[j]==target){
                    target_cnt++;


                }
                int len_subarr=j-i+1;
                if (target_cnt>(len_subarr)/2){
                    sub_arr_cnt++;
                }
            }
        }
        return sub_arr_cnt;

        
    }
};

// optimal soln:
//not udnerstood yet

class Solution {
private:
    int treeSize;
    vector<int> bit;

    void update(int idx, int val) {
        for (; idx < treeSize; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        treeSize = 2 * n + 5;
        bit.assign(treeSize, 0);

        int offset = n + 2; 
        int currSum = 0;
        
        update(currSum + offset, 1);
        
        long long totalSubarrays = 0;
        
        for (int num : nums) {
            if (num == target) {
                currSum += 1;
            } else {
                currSum -= 1;
            }
            
            totalSubarrays += query(currSum + offset - 1);
            update(currSum + offset, 1);
        }
        
        return totalSubarrays;
    }
};