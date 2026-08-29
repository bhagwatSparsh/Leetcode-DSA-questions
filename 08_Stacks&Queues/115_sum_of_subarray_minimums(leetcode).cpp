// brute force soln:
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int min_i=0;
        int mod=(int)1e9 + 7;
        int n=arr.size();
        for (int i=0;i<n;i++){
            min_i=arr[i];
            for (int j=i;j<n;j++){
                min_i=min(min_i,arr[j]);
                sum=(sum+min_i)%mod;
            }
        }
        return sum;
        
    }
};

// optimal soln: 

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        
        vector<int> ple(n), nle(n);
        stack<int> st;
        
        // 1. Find Previous Less Element (strictly less)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ple[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        
        // Clear stack for next pass
        while (!st.empty()) st.pop();
        
        // 2. Find Next Less or Equal Element (less than or equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nle[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        
        // 3. Compute total contribution
        long long total_sum = 0;
        for (int i = 0; i < n; i++) {
            long long count = (1LL * ple[i] * nle[i]) % mod;
            long long contribution = (count * arr[i]) % mod;
            total_sum = (total_sum + contribution) % mod;
        }
        
        return total_sum;
    }
};