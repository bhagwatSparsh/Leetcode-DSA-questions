// brute force approach:

class Solution {
public:
    int floorSqrt(int n)  {
        
        int ans=1;
        for (int i=0;i<n;i++){
            int val=i*i;
            if(val<=n){
                ans=i;

            }

        }
        return ans;
      
    }
};

// binary search approach:
class Solution {
public:
    int floorSqrt(int n)  {
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int val=mid*mid;
            if (val<=n){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
      
    }
};