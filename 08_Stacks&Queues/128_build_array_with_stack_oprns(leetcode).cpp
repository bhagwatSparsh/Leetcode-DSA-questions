class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int stream=1;
        int i=0;
        while ( i<target.size() && stream<=n ){
            res.push_back("Push");

            if (target[i] == stream){       
                i++;

            }
            else{
                res.push_back("Pop");
            }
            stream++;
            
        }
        return res;
        
        
    }
};