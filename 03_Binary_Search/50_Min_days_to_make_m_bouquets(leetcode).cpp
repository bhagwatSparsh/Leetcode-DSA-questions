// brute force approach:
class Solution {
public:
    int if_possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int no_of_bouq = 0;
        int n = bloomDay.size();

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                no_of_bouq += (cnt / k);
                cnt = 0;
            }
        }
        no_of_bouq += (cnt / k);
        return no_of_bouq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
   
        if ((long long)m * k > n) {
            return -1;
        }

       
        int min_day = bloomDay[0];
        int max_day = bloomDay[0];
        for (int i = 0; i < n; i++) {
            min_day = min(min_day, bloomDay[i]);
            max_day = max(max_day, bloomDay[i]);
        }
        for (int day = min_day; day <= max_day; day++) {
            if (if_possible(bloomDay, day, m, k) >= m) {
                return day; 
            }
        }

        return -1;
    }
};

// optimal solution using binary search:

class Solution {
public:
    int if_possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt = 0;
        int no_of_bouq = 0;
        int n = bloomDay.size();

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                no_of_bouq += (cnt / k);
                cnt = 0;
            }
        }
        no_of_bouq += (cnt / k);
        return no_of_bouq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
   
        if ((long long)m * k > n) {
            return -1;
        }

       
        int min_day = bloomDay[0];
        int max_day = bloomDay[0];
        for (int i = 0; i < n; i++) {
            min_day = min(min_day, bloomDay[i]);
            max_day = max(max_day, bloomDay[i]);
        }
        int low=min_day;
        int high=max_day;
        while(low<=high){
            int mid=(low+high)/2;
            if (if_possible(bloomDay, mid, m, k)>=m){
                high=mid-1;

                
            }
            else{
                low=mid+1;

            }
        }


        return low;
    }
};