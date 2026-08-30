#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); // Default all to 0
        stack<pair<int, int>> st; // Stores {temperature, index}

        for (int i = 0; i < n; i++) {
            // While today is warmer than the temperature at the top of the stack
            while (!st.empty() && temperatures[i] > st.top().first) {
                int prevIndex = st.top().second;
                st.pop();
                ans[prevIndex] = i - prevIndex;
            }
            // Push current day's temperature and index
            st.push({temperatures[i], i});
        }

        return ans;
    }
};