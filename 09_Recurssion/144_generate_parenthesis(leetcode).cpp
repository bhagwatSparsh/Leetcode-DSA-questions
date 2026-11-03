//APPROACH -1 :

class Solution {
public:
    vector<string> res;

    bool is_valid(string &str){
        int count=0;
        for (char ch: str){
            if (ch=='('){
                count++;
            }
            else{
                count--;
            }
            if (count<0){
                return false;
            }
        }
        return count==0;
    }

    void solve(string &curr, int n){
        if (curr.size()==2*n){
            if(is_valid(curr)){
                res.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();

    }

    vector<string> generateParenthesis(int n) {
        
        string curr="";
        solve(curr,n);
        return res;

        
        
    }
};

// APPROACH -2:
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(vector<string> &res, string &curr, int open, int close, int n) {
        // Base case: string reached the maximum valid length (2 * n)
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        // Decision 1: Add an opening bracket if we haven't used all 'n'
        if (open < n) {
            curr.push_back('(');
            backtrack(res, curr, open + 1, close, n);
            curr.pop_back(); // Backtrack
        }

        // Decision 2: Add a closing bracket only if it doesn't exceed opened ones
        if (close < open) {
            curr.push_back(')');
            backtrack(res, curr, open, close + 1, n);
            curr.pop_back(); // Backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        backtrack(res, curr, 0, 0, n);
        return res;
    }
};