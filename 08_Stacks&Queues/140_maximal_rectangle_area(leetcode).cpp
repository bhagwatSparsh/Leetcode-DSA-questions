// prefix sum + largest rectangle histogram problem:

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Optimal 1-pass Largest Rectangle in Histogram logic
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int max_area = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int elem = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                max_area = max(max_area, (nse - pse - 1) * heights[elem]);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int nse = n;
            int elem = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();

            max_area = max(max_area, (nse - pse - 1) * heights[elem]);
        }

        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int max_rectangle = 0;

        for (int i = 0; i < rows; i++) {
            // Update heights histogram for the current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0; // Reset height if broken by '0'
                }
            }

            // Find the max area under the histogram formed by the current row
            max_rectangle = max(max_rectangle, largestRectangleArea(heights));
        }

        return max_rectangle;
    }
};