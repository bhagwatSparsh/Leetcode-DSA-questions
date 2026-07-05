class Solution {
public:

    int subtractProductAndSum(int n) {
        long long pdt=1;
        long long sum=0;
        while(n!=0){
            long long digit=n%10;
            pdt=pdt*digit;
            sum+=digit;
            n=n/10;

        }
        int ans=pdt-sum;
        return ans;
        
    }
};