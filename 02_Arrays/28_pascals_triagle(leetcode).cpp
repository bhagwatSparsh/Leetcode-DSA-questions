// brute solution:


class Solution {
public:
    int ncr(int n, int r){
        long long res=1;
        for (int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i=0;i<numRows;i++){
            vector<int> row;
            for (int j=0;j<=i;j++){
                row.push_back(ncr(i,j));
            }
            ans.push_back(row);

        }
        return ans;
        
    }
};
//optimal soilution:

class Solution {
public:
    vector<int> generate_row(int row){
        long long ans=1;
        vector<int> ans_row;
        ans_row.push_back(1);
        for (int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            ans_row.push_back(ans);
        }
        return ans_row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i=1;i<=numRows;i++){
            res.push_back(generate_row(i));
        }
        return res;
        
        
    }
};