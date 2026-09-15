class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        int nums_3=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if (nums[i] < nums_3){
                return true;
            }

            while(!st.empty() && st.top() < nums[i]){ // jabtak st.top() nums[i] se choota hai
                nums_3=st.top(); // assign (candidate) for second largest
                st.pop();

            }

            st.push(nums[i]);


        }
        return false;
    }
};