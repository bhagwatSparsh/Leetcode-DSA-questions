

class Solution {
public:
    // Helper function to find the count of elements <= x in a sorted row
    int upper_bound(vector<int> &nums, int x, int m) {
        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents potential integer overflow
            if (nums[mid] <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low; // 'low' will represent the count of elements <= x
    }

    // Counts how many elements in the entire matrix are <= x
    int cnt_small_equals(vector<vector<int>> &matrix, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upper_bound(matrix[i], x, m); // Fixed: added missing semicolon
        }
        return cnt;
    }
    
    int findMedian(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Fixed: Initialize low to INT_MAX so min() works correctly
        int low = INT_MAX; 
        int high = INT_MIN;
        
        // Find the absolute minimum and maximum elements in the matrix
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }
        
        // The position we are looking for (0-indexed median requirement)
        int req = (n * m) / 2;
        
        // Binary search over the value range [low, high]
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Count how many numbers in the matrix are <= mid
            if (cnt_small_equals(matrix, n, m, mid) <= req) {
                low = mid + 1; // Median must be greater than mid
            } else {
                high = mid - 1; // Median could be mid or smaller
            }
        }
        return low;
    }
};