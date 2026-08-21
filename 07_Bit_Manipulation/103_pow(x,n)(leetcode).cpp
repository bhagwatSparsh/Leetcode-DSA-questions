// brute force approach:

class Solution {
public:
    double myPow(double x, int n) {
        double ans=x;
        for(int i=1;i<n;i++){
            if (n>=0){
                ans=ans*x;

            }
            else{
                ans=1/(ans*x);

            }
            

        }
        return ans;
        
    }
    
};
// optimal soln:

class Solution {
public:
    double solve(double x, long n){
        // we will use recurssion to solve this problem in optimal soln
        if (n==0){
            return 1;
        }
        if (n<0){
            return solve(1/x,-n);
        }
        if (n%2==0){
            return solve(x*x, n/2);

        }
        return x*solve(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        return solve(x, (long)n);
        
    }
};