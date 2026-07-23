// brute force soln:
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> store_unique;
        
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++){
                    int store=nums[i]^nums[j]^nums[k];
                    store_unique.insert(store);
                }
            }
        }
        return store_unique.size();
        
    }
};
// optimal soln using bit manipulation:

// find nearest power of 2 after n is 2^k where k is the number of bits required to represent n. The number of unique XOR triplets will be equal to 2^k.
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        
        // __builtin_clz gives count of leading zeros in a 32-bit integer
        int bitLength = 32 - __builtin_clz(n);
        return 1 << bitLength;
    }
};

// logn n time comp:
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if (n==1 || n==2){
            return n;
        }
        int ans=1;// 2^0 start off
        while(ans<=n){
            ans=ans*2; // nearest power of 2 which is juts greater than n:
            // logic is bit manipulation by 2^k logic


        }
        return ans;

    }
};