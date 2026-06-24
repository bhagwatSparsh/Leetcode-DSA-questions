// brute force soln:

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        int len_first_string=strs[0].size();
        int len_vec=strs.size();
        
        for (int i=0;i<len_first_string;i++){
            char ch=strs[0][i];
            for (int j=1;j<len_vec;j++){
                if (i==strs[j].size() || strs[j][i]!=ch){
                    return strs[0].substr(0,i);
                }
            }

        }
        return strs[0];

        
    }
};

// optimal soln:

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string res = "";
        
        // loop by the minimum length of the two strings
        int max_possible_length = min(first.length(), last.length());
        for (int i = 0; i < max_possible_length; i++){
            if (first[i] == last[i]){
                res += first[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};
