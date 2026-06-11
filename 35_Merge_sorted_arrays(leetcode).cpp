
// brute force solution:

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        
       
        for (int i = 0; i < m; i++){
            ans.push_back(nums1[i]);
        }
       
        for (int i = 0; i < n; i++){
            ans.push_back(nums2[i]);
        }
      
        sort(ans.begin(), ans.end());
        nums1 = ans; 
    }
};

// optimal solution 1:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;
        while(left>=0 && right<n){
            if (nums1[left]>nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else{
                break;

            }
        }
        for (int i=0;i<n;i++){
            nums1[m+i]=nums2[i];

        }
        sort(nums1.begin(), nums1.end());

        
        
    }
};

// optimal solution 2: USING SHELL SORT ALGORIHHTM:
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int totalSize = m + n;
        int gap = (totalSize / 2) + (totalSize % 2);
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            while (right < totalSize) {
                if (left < m && right < m) {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                } else if (left < m && right >= m) {
                    if (nums1[left] > nums2[right - m]) {
                        swap(nums1[left], nums2[right - m]);
                    }
                } else if (left >= m && right >= m) {
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }
                left++;
                right++;
            }
            if (gap == 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};