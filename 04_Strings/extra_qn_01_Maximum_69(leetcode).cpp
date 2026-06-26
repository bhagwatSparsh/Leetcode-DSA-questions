class Solution {
public:
    int maximum69Number (int num) {
        string num_str=to_string(num);

        int len=num_str.size();
        for (int i=0;i<len;i++){
            if (num_str[i]=='6'){
                num_str[i]='9';
                break;
            }
        }
        return stoi(num_str);

        
    }
};