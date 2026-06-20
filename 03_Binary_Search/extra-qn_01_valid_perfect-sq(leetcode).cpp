// brute force sol:

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num==1 || num==0){
            return true;
        }
        for (long long i=1;i<=num/2;i++){
           long long pdt=(i*i);
           if (pdt==num){
            return true;
           }

        }
        return false;
        
    }
};

// optimal soln:
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=0;
        int high=num;
        while(low<=high){
            long long mid=(low+high)/2;
            long long pdt=mid*mid;
            if (pdt==num){
                return true;

            }
            else if(pdt<num){
                low=mid+1;

            }
            else{
                high=mid-1;
            }
        }
        return false;
        
    }
};