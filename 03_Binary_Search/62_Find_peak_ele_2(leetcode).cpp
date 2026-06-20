// brute force soln:
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int start=INT_MIN;
        int end=INT_MIN;
        int max_i=INT_MIN;
        int curr_i=INT_MIN;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                curr_i=mat[i][j];
                if (curr_i>max_i){
                    max_i=curr_i;
                    start=i;
                    end=j;
                }
                


            }
        }
        return {start, end};

        
    }
};

// optimal soln:

class Solution {
public:
    int max_row_elem_idx(vector<vector<int>> &mat, int m, int  n, int colm){
        m=mat.size();
        n=mat[0].size();
        int max_row=INT_MIN;
        int idx=-1;
        for (int i=0;i<m;i++){
            if (mat[i][colm]>max_row){
                max_row=mat[i][colm];
                idx=i;
            }



        }
        return idx;

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int max_row_idx=max_row_elem_idx(mat,m,n,mid);
            int left=-1;
            int right=-1;
            
            if (mid-1>=0){
                left=mat[max_row_idx][mid-1];
            }
            else{
                left=-1;

            }
            if (mid+1<n){
                right=mat[max_row_idx][mid+1];
            }
            else{
                right=-1;
            }
            if (mat[max_row_idx][mid]> left && mat[max_row_idx][mid]> right){
                return {max_row_idx, mid};
            }
            else if(mat[max_row_idx][mid]< left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
        
    }
};
