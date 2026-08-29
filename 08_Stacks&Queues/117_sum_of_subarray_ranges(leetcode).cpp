// brute force:

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for (int i=0;i<n;i++){
            int largest=nums[i];
            int smallest=nums[i];
            for (int j=i+1;j<n;j++){
                largest=max(largest, nums[j]);
                smallest=min(smallest, nums[j]);
                sum+=largest-smallest;
            }
            



        }
        return sum;
        
    }
};

// optimal soln:
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum_min = 0, sum_max = 0;
        stack<int> st;

        // 1. Calculate Sum of Subarray Minimums
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] >= nums[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                sum_min += (long long)nums[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // 2. Calculate Sum of Subarray Maximums
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || nums[st.top()] <= nums[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                sum_max += (long long)nums[mid] * (mid - left) * (right - mid);
            }
            st.push(i);
        }

        return sum_max - sum_min;
    }
};