class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_i=prices[0];
        int max_profit=0;
        for (int i=1;i<n;i++){
            int cost=prices[i]-min_i;
            max_profit=max(max_profit,cost);
            min_i=min(min_i, prices[i]);
        }
        return max_profit;
        
    }
};
