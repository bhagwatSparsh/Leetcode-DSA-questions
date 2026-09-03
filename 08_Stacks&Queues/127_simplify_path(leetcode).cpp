class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string token="";

        stringstream ss(path); // get the tokens from string:
        
        while(getline(ss, token, '/' )){
            if (token=="" || token==".") continue;
            else if( token!=".."){
                st.push(token);

            }
            else{
                if (!st.empty()){
                    st.pop();

                }
                

            }
        }
        string res="";
        if (st.empty()){
            return "/";
        }
        while(!st.empty()){
            res="/" + st.top() + res;
            st.pop();

        }
        return res;
        
    }
};