// brute force soln:
class Solution {
public:
    int minimumPushes(string word) {
        int sum=0;
        int n=word.size();
        for (int i=0;i<n;i++){
            if (i<8){
                sum+=1;


            }
            else if (i<16 && i>=8){
                sum+=2;
            }
            else if (i<24 && i>=16){
                sum+=3;

            }
            else{
                sum+=4;
            }
        }
        return sum;

        
    }
};

// optimal soln:

class Solution {
public:
    int minimumPushes(string word) {
        int sum=0;
        int n=word.size();
        for (int i=0;i<n;i++){
            sum+=i/8 + 1;
            
        }
        return sum;

        
    }
};