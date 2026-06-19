// brute force soln:

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool is_present=false;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (matrix[i][j]==target){
                    is_present=true;

                }
            }
        }
        return is_present;
    }
};
// optimal soln:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=(m*n-1);
        // flattening of 2d array to 1d array concept
        
        while(low<=high){
            int mid=(low+high)/2;
            // formula to get equivalent row and column in 1d array;
            int row=mid/n;
            int colm=mid%n;
            if (matrix[row][colm]==target){
                return true;

            }
            else if(matrix[row][colm]<target){
                low=mid+1;

            }
            else{
                high=mid-1;

            }
        }
        return false;
        
    }
};