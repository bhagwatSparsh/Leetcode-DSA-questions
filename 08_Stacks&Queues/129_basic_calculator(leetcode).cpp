class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        long long num=0;
        int sign=1; // can be +1 or -1
        int res=0;
        stack<int> st;


        for (int i=0;i<n;i++){
           if (isdigit(s[i])){ // if s[i] is digit then number banate jao till you get operator:

            num=(num*10) + (s[i]-'0'); 
            
           } 
           else if(s[i]=='+'){
            res+=(num*sign);
            num=0;
            sign=1;

           }
           else if(s[i]=='-'){
            res+=(num*sign);
            num=0;
            sign=-1;

           }
           else if(s[i]=='('){
            st.push(res); // push res till now into stack;
            st.push(sign); // push sign till now in stack

            num=0;
            res=0;
            sign=1;




           }
           else if(s[i]==')'){
            res+=(num*sign);
            num=0;

            int stack_sign=st.top();
            st.pop();
            int stack_last_res=st.top();
            st.pop();

            res=(res*stack_sign);
            res+=stack_last_res;
            
           }

        }
        res+=(num*sign); // check if any no is left
        return res;
        
    }
};