// better approach:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 

        sort(nums.begin(), nums.end());

        int longest_streak = 1;
        int current_streak = 1;

        for (int i = 1; i < n; i++) {
            
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            
            
            if (nums[i] == nums[i - 1] + 1) {
                current_streak += 1;
            } else {
                longest_streak = max(longest_streak, current_streak);
                current_streak = 1;
            }
        }

        
        return max(longest_streak, current_streak);
    }
};

// optimal solution:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if (n==0){
            return 0;
        }
        unordered_set<int> st(nums.begin(), nums.end());
        int longest=1;

        for (auto it: st){
            if (st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    
                    cnt+=1;
                    x+=1;

                }
                longest=max(longest,cnt);

            }
            
        }
        return longest;

        
    }
};
