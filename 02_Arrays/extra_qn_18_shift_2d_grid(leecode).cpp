// brute force soln:
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        k=k%(m*n);
        for (int step=0;step<k;step++){
            vector<vector<int>> new_grid(m, vector<int>(n,0));
            for (int i=0;i<m;i++){
                for (int j=0;j<n;j++){
                    if (i==m-1 && j==n-1){
                        new_grid[0][0]=grid[i][j];
                    }
                    else if(j==n-1){
                        new_grid[i+1][0]=grid[i][n-1];
                    }
                    else{
                        new_grid[i][j+1]=grid[i][j];
                    }
                }
            }
            grid=new_grid;
        }
        return grid;
        
    }
};

// optimal soln:
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // we  will use the logic of flattening of matrix  by conv 2d to 1d matrix in mind:
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        k=k%total;// eliminate to reduce search space and time
        vector<vector<int>> ans(m, vector<int>(n,0));

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int new_1d=i*n+j; // 1d array conv
                int after_shift=(new_1d+k) % total; // shift in array 1d
                int new_row=(after_shift)/n;
                int new_col=after_shift%n;

                ans[new_row][new_col]=grid[i][j];

            }

        }
        return ans;

        
    }
};