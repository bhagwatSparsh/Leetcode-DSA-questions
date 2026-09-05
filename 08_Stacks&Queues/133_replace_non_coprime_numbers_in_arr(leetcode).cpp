#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int gcd(int a, int b){ // calc gcd of elements
        if (b == 0){
            return a;
        }
        return gcd(b, a % b);
    }

    int lcm(int a, int b){ // calc lcm of elements make sure of  overflow
        long long pdt = (long long)a * b;
        int lcm_no = pdt / gcd(a, b);
        return lcm_no;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i]; 

            while (!st.empty() && gcd(st.top(), curr) > 1) {
                // we have to specify !st.empty() to get out of while loop
                curr = lcm(st.top(), curr);
                st.pop();
            }

            st.push(curr);
        }

        vector<int> res(st.size());
        for (int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};