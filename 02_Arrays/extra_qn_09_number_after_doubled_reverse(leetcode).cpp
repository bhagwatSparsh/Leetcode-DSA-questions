class Solution {
public:
    int rev_no(int num){
        int rev=0;
        while(num!=0){
            int digit=num%10;
            rev=rev*10+digit;
            num=num/10;
        }
        return rev;


    }

    bool isSameAfterReversals(int num) {
        
        int rev_1=rev_no(num);
        int rev_2=rev_no(rev_1);
        if (rev_2==num){
            return true;

        }
        return false;


        
    }
};