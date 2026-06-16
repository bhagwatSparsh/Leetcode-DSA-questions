// brute force solution:
class Solution {
public:
    long long findTimeReq(vector<int>& piles, int k) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1) / k;  
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());

        for (int k = 1; k <= maxPile; k++) {
            if (findTimeReq(piles, k) <= h) {
                return k;
            }
        }

        return maxPile;
    }
};

// optimal solution using binary search:

class Solution {
public:
    int max_ele(vector<int>& piles){
        int max_i = 0;

        for(int i = 0; i < piles.size(); i++){
            max_i = max(max_i, piles[i]);
        }

        return max_i;
    }

    long long calc_time(vector<int>& piles, int k){
        long long time_req = 0;

        for(int i = 0; i < piles.size(); i++){
            time_req += ((long long)piles[i] + k - 1) / k;
        }

        return time_req;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_val = max_ele(piles);

        int low = 1;
        int high = max_val;
        int ans = max_val;

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long total_time_req = calc_time(piles, mid);

            if(total_time_req <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};