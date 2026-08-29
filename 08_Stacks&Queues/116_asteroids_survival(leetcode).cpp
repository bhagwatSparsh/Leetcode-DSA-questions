class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        
        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                ans.push_back(asteroids[i]);
            }
            else {
                // Destroy smaller right-moving asteroids
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])) {
                    ans.pop_back();
                }
                
                // If top asteroid is same size, both destroy each other
                if (!ans.empty() && ans.back() == abs(asteroids[i])) {
                    ans.pop_back();
                }
                // If stack is empty or top is also moving left, current asteroid survives
                else if (ans.empty() || ans.back() < 0) {
                    ans.push_back(asteroids[i]);
                }
            }
        }
        return ans;
    }
};