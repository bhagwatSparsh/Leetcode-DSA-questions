class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n=pushed.size();
        int m=popped.size();
        int i=0, j=0;
        while(i<n && j<m){
            st.push(pushed[i]);
            while (!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
        
    }
};