// brute force soln:

class Solution {
public:   
    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size(); 
        
        int max_cnt = 0;
        int max_row_index = -1; 
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    cnt++;
                }
            }
            // Update only if we find a row with strictly MORE 1s
            if (cnt > max_cnt) {
                max_cnt = cnt;
                max_row_index = i;
            }
        }
        
        return max_row_index;
    }
};

// optimal solution:

class Solution {
  public:   


  int lower_bound(vector<int> &nums, int x){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=n;// so that if no 1 is found, it return 0
    while(low<=high){
        int mid=(low+high)/2;
        if (nums[mid]>=x){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;

        }
    }
    return ans;
  }
  int rowWithMax1s(vector < vector < int >> & mat) {
    int n=mat.size();
    int idx=-1;
    int max_cnt=0;
    for (int i=0;i<n;i++){
        int cnt=n-lower_bound(mat[i],1);
        if (cnt>max_cnt){
            max_cnt=cnt;
            idx=i;
        }
    }
    return idx;

  }
};