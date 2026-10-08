class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string res="";
        int depth=0;

        for (char ch: s){
            if (ch=='('){
                if (depth>=1){
                    res+=ch;
                    
                    
                }
                depth++;
            }
            else{
                depth--;
                if (depth>=1){
                    res+=ch;
                }

            }
        }
        return res;
        

    }
};