// brute force soln using nse and pse:

class Solution {
public:
    vector<int> next_smallest_element(vector<int>& heights){
        int n=heights.size();
        stack<int> st;
        vector<int> nse(n); 

        // start traversal from the right to get the next smallest element elem bcz we want to compare element from right
        for (int i=n-1;i>=0;i--){
            // while st.top() is not less or smaller, means we have to continue popping to get next smallest element as the netx element is larger.
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();

            }
            // if we have started or popped out everything from stack which means no next smallest element: In this qn if no next smallest element we will return size(n)
            nse[i]= st.empty() ? n : st.top();
            //push into stack for subsequent elements nse;
            st.push(i);
        }
        return nse;

    }
    vector<int> prev_smallest_elem(vector<int>& heights){
        int n=heights.size();
        vector<int> pse(n);
        stack<int> st;
        // same just traverse from left to right:
        for (int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            pse[i]= st.empty() ? -1 : st.top();
            st.push(i);

        }
        return pse;

    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int max_i=0;
        vector<int> nse = next_smallest_element(heights);
        vector<int> pse = prev_smallest_elem(heights);
        for (int i=0;i<n;i++){
            max_i=max(max_i, heights[i] * (nse[i] - pse[i] - 1));

            

        }
        return max_i;
        
    }
};

// optimal soln:

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;

        for (int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int elem = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                max_area = max(max_area, (nse - pse - 1) * heights[elem]);
            }

            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int elem = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();

            max_area = max(max_area, (nse - pse - 1) * heights[elem]);
        }
        
        return max_area;
    }
};