// brute force soln:

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {
            int foundIdx = -1;
            
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    foundIdx = j;
                    break;
                }
            }

            // 2. Search to the right for the first greater element
            int nextGreater = -1;
            for (int k = foundIdx + 1; k < m; k++) {
                if (nums2[k] > nums2[foundIdx]) {
                    nextGreater = nums2[k];
                    break;
                }
            }
            ans.push_back(nextGreater);
        }
        return ans;
    }
};

// optimal soln: MONOTIC STACK APPROACH:
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> nge_map;
        stack<int> st;
        int n=nums2.size();
        for (int i=n-1;i>=0;i--){
            while (!st.empty() && st.top()< nums2[i]){
                st.pop();
            }
            if (st.empty()){
                nge_map[nums2[i]]=-1;
            }
            else{
                nge_map[nums2[i]]=st.top();

            }
            st.push(nums2[i]);
        }

        int m=nums1.size();
        for (int i=0;i<m;i++){
            ans.push_back(nge_map[nums1[i]]); // maps  all those elements that are there in nums1 and in nums2 but acc to nge in nums2;

        }
        return ans;
        
    }
};