// brute force soln: TLE:

class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i < num; ++i) {
            if (num % i == 0) {
                return false; 
            }
        }
        return true;
    }

   
    int countPrimes(int n) {
        int count = 0;
        
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                count++;
            }
        }
        
        return count;
    }
};

// optimal soln: sieve of erathosthenes

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> isPrime(n,true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2;i*i < n;i++){
            if(isPrime[i]){
                for(int j=i*i ; j<n ;j+=i){
                    isPrime[j] = false;
                }
            }
        }
         int cnt=0;
         for(int i=2;i<n;i++){
            if(isPrime[i]){
                cnt++;
            }
         }
         return cnt;
    }
};