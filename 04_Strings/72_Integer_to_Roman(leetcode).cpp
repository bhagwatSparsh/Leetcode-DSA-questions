class Solution {
public:
    string intToRoman(int num) {
        
        vector<pair<int, string>> roman={
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},
            {50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        int n=roman.size();
        string ans="";

        for (int i=0;i<n;i++){
            while(num>=roman[i].first){
                ans+=roman[i].second;
                num=num-roman[i].first;

            }

            

        }
        return ans;
        
    }
};
