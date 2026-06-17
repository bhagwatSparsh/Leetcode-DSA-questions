// optimal solution:

class Solution {
public:
    int mySqrt(int x) {
        if (x<2){
            return x;
        }
        int low=1;
        int high=x;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (mid<=x/mid){
                low=mid+1;
            }
            else{
                high=mid-1;

            }
        }
        return low-1;
    }
};