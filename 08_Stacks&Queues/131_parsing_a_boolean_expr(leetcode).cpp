class Solution {
public:
    char cal_opr_value(vector<char>& values, char opr){
        
        if (opr=='!'){
            if (values[0]=='t'){ // to check for negation check the forst value of the expression 
                return 'f';
            }
            return 't';
        }
        if (opr=='&'){
            for (char &ch : values){
                if (ch=='f'){
                    return 'f';
                }
            }
            return 't';
        }
        if (opr=='|'){
            for (char &ch : values){
                if (ch=='t'){
                    return 't';
                }
            }
            return 'f';
        }
        return 't';

    }
    bool parseBoolExpr(string expression) {
        int n=expression.size();

        stack<char> st;
        for (int i=0;i<n;i++){
            if (expression[i]==','){ // if we get a comman then continue forward
                continue;
            }

            else if(expression[i]==')'){ // the moment we get a closing bbracket, we pop pout till we get an opening bracket
                vector<char> store;
                while(!st.empty() && st.top()!='('){
                    char ch=st.top();
                    store.push_back(ch);
                    st.pop();
                }
                // pop the opening bracket:
                st.pop();
                char opr=st.top(); 
                char cal_value=cal_opr_value(store, opr);
                st.push(cal_value); // push the calc value expression back ontoo the stack



            }
            else{
                st.push(expression[i]);
            }
        }
        if (st.top()=='t'){
            return true;

        }
        return false;
        
    }
};