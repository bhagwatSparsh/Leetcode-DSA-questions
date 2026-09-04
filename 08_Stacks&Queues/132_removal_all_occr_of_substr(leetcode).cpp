class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res="";
        int n=part.size();
        
        for (char &ch:s){
            res.push_back(ch);
            // we push each ch in string res;
            // we check if substr till one part is equal to part, if yes erase it;
            if (res.length()>=n && res.substr(res.length()-n)==part){  // only if len>=n
                res.erase(res.length()-n); 
            }
        }
        return res;
        
    }
};