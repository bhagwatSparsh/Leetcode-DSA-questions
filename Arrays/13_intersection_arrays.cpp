//349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> inter;
        
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                i++; 
            } 
            else if (nums2[j] < nums1[i]) {
                j++; 
            } 
            else {
               
                if (inter.empty() || inter.back() != nums1[i]) {
                    inter.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return inter;
    }
};