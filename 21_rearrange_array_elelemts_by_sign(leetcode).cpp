// Brute-force approach: 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        
        vector<int> pos_arr(n);
        int cnt_1 = 0;
        vector<int> neg_arr(n);
        int cnt_2 = 0;
        
        for (int i = 0; i < n; i++){
            if (nums[i] > 0){
                pos_arr[cnt_1] = nums[i];
                cnt_1++;
            }
            else {
                neg_arr[cnt_2] = nums[i];
                cnt_2++;
            }
        }
        
        int pos_ptr = 0;
        int neg_ptr = 0;
        
        for (int i = 0; i < n; i += 2){
            nums[i] = pos_arr[pos_ptr];
            pos_ptr++;
            
            nums[i+1] = neg_arr[neg_ptr];
            neg_ptr++;
        }
        
        return nums;
    }
};

//optimal solution:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int pos_idx=0;
        int neg_idx=1;
        for (int i=0;i<n;i++){
            if (nums[i]<0){
                ans[neg_idx]=nums[i];
                neg_idx+=2;

            }
            else{
                ans[pos_idx]=nums[i];
                pos_idx+=2;

            }
        }
        return ans;
        
    }
};

// if size is unequal of postive and negative numbers:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pos_arr(n);
        int cnt_1 = 0;
        vector<int> neg_arr(n);
        int cnt_2 = 0;
        
        for (int i = 0; i < n; i++){
            if (nums[i] > 0){
                pos_arr[cnt_1] = nums[i];
                cnt_1++;
            }
            else {
                neg_arr[cnt_2] = nums[i];
                cnt_2++;
            }
        }
        
        int nums_ptr = 0;
        int pos_ptr = 0;
        int neg_ptr = 0;
        
        int min_length = min(cnt_1, cnt_2);
        
        for (int i = 0; i < min_length; i++) {
            nums[nums_ptr] = pos_arr[pos_ptr];
            pos_ptr++;
            nums_ptr++;
            
            nums[nums_ptr] = neg_arr[neg_ptr];
            neg_ptr++;
            nums_ptr++;
        }
        
        for (int i = pos_ptr; i < cnt_1; i++) {
            nums[nums_ptr] = pos_arr[i];
            nums_ptr++;
        }
        
        for (int i = neg_ptr; i < cnt_2; i++) {
            nums[nums_ptr] = neg_arr[i];
            nums_ptr++;
        }
        
        return nums;
    }
};