// brute force soln: 
class Solution {
public:
    int left_max(vector<int> &height, int x){
        int n=height.size();
        vector<int> prefix_max(n);
        prefix_max[0]=height[0];
        for (int i=1;i<n;i++){
            prefix_max[i]=max(prefix_max[i-1], height[i]);

        }
        return prefix_max[x];


    }
    int right_max(vector<int> &height, int x){
        int n=height.size();
        vector<int> suffix_max(n);
        suffix_max[n-1]=height[n-1];
        for (int i=n-2;i>=0;i--){
            suffix_max[i]=max(suffix_max[i+1], height[i]);
        }
        return suffix_max[x];
    }
    
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        for (int i=0;i<n;i++){
            if (height[i]<left_max(height, i) && height[i]<right_max(height, i)){
                total+=min(left_max(height, i), right_max(height, i))-height[i];
            }
        }

        return total;

        
    }
};
// better soln: precompute prefix and suffix max arrays and then calculate the trapped water in a single pass

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left_max(n), right_max(n);

        // Precompute prefix max
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        // Precompute suffix max
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        // Calculate trapped water
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += min(left_max[i], right_max[i]) - height[i];
        }

        return total;
    }
};

// optimal soln: two pointer approach

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int total = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    total += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    total += right_max - height[right];
                }
                right--;
            }
        }

        return total;
    }
};