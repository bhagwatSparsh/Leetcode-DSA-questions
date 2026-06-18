//  brute force solution:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> res;

        for (int i=0;i<n1;i++){
            res.push_back(nums1[i]);
        }
        for (int i=0;i<n2;i++){
            res.push_back(nums2[i]);
        }
        sort(res.begin(), res.end());
        int size=res.size();
        if (size%2==0){
            return (res[size/2]+ res[(size/2)])/2;

        }
        else{
            return res[size/2];
        }
        
    }
};

// better solution using merge sort and two pointers:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = 0;
        int right = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> temp;
        while(left < n1 && right < n2){
            if (nums1[left] < nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
            else{
                temp.push_back(nums2[right]);
                right++;
            }
        }
     
        while (left < n1){
            temp.push_back(nums1[left]);
            left++;
        }
        
      
        while (right < n2){
            temp.push_back(nums2[right]);
            right++;
        }
        
     
        int size = temp.size();
        if (size % 2 == 0){
        
            return (temp[size / 2] + temp[(size / 2) - 1]) / 2.0;
        }
        else{
            return temp[size / 2];
        }
    }
};

// optimal solution using binary search:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if (n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low=0;
        int high=n1;
        int n=(n1+n2);
        int left=(n1+n2+1)/2;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if (mid1<n1){
                r1=nums1[mid1];
            }
            if (mid2<n2){
                r2=nums2[mid2];
            }
            if (mid1-1>=0){
                l1=nums1[mid1-1];
            }
            if (mid2-1>=0){
                l2=nums2[mid2-1];
            }
            if (l1<=r2 && l2<=r1){
                if (n%2==1){
                    return max(l1,l2);
                }
                else{
                    return ((double)(max(l1,l2) + min(r1,r2)))/2.0;

                }
            }
            else if(l1>r2){
                high=mid1-1;

            }
            else{
                low=mid1+1;
            }

        }
        return 0;
        
    }
};
