class Solution {
public:
    void all_possb_combinations(vector<int> &arr, int idx, int target, vector<vector<int>> &ans, vector<int> &combin) {
        // 1. Check success first
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        // 2. Base conditions for failure
        if (target < 0 || idx == arr.size()) {
            return;
        }
        // funda: each elemnt is picked once or not picked code:
        
        // --- CHOICE 1: Pick arr[idx] ---
        combin.push_back(arr[idx]);
        // Recurse to idx + 1 because each element is used at most once
        all_possb_combinations(arr, idx + 1, target - arr[idx], ans, combin);

        // Backtrack
        combin.pop_back();

        // --- CHOICE 2: Don't pick arr[idx] ---
        // Skip identical numbers to prevent duplicate combinations and TLE
        while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) {
            idx++;
        }
        all_possb_combinations(arr, idx + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sorting is required to cluster duplicates together
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combin;
        all_possb_combinations(candidates, 0, target, ans, combin);
        return ans;
    }
};