class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth=0;
        int rows=accounts.size();
        int colmn=accounts[0].size();
        for (int i=0;i<rows;i++){
            int curr_wealth=0;
            for (int j=0;j<colmn;j++){
                curr_wealth+=accounts[i][j];
            }
            if (curr_wealth>max_wealth){
                max_wealth=curr_wealth;
            }
            

        }
        return max_wealth;
        
    }
};