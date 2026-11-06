class Solution {
public:
    set<vector<int>> s;
    void all_possb_combinations(vector<int>  &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combin){

        if(target<0 || idx==arr.size()){
            
            return;
        }

        if (target==0){
            if (s.find(combin)==s.end()){
                ans.push_back({combin});
                s.insert(combin);
            }
            return;
        }

        combin.push_back(arr[idx]);
        //single selection:
        all_possb_combinations(arr, idx+1, target-arr[idx],ans, combin);
        //multiple selection:
        all_possb_combinations(arr, idx, target-arr[idx],ans, combin);
        // no selection:
        combin.pop_back();
        all_possb_combinations(arr, idx+1, target,ans, combin);
        return;



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        all_possb_combinations(candidates, 0, target, ans, combin);
        return ans;
        
    }
};