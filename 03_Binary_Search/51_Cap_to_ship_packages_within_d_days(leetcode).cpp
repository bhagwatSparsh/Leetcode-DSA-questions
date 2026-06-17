// brute force solution:
class Solution {
public:
    int days_taken(vector<int>& weights, int cap){
        int load=0;
        int days=1;
        int n=weights.size();
        for (int i=0;i<n;i++){
            if (load+weights[i]> cap){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];

            }

        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min_cap=weights[0];
        int max_cap=weights[0];
        int n=weights.size();
        for (int i=0;i<n;i++){
            min_cap=max(min_cap, weights[i]);
            max_cap+=weights[i];

        }
        for (int i=min_cap; i<= max_cap;i++){
            if (days_taken(weights,i)<=days){
                return i;
            }
        }
        return max_cap;
        
    }
};

// optimal solution:

class Solution {
public:
    int days_taken(vector<int>& weights, int cap){
        int load=0;
        int days=1;
        int n=weights.size();
        for (int i=0;i<n;i++){
            if (load+weights[i]> cap){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];

            }

        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min_cap=weights[0];
        int max_cap=weights[0];
        int n=weights.size();
        for (int i=0;i<n;i++){
            min_cap=max(min_cap, weights[i]);
            max_cap+=weights[i];

        }
        int low=min_cap;
        int high=max_cap;
        while(low<=high){
            int mid=(low+high)/2;
            if (days_taken(weights, mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;

        
        
    }
};