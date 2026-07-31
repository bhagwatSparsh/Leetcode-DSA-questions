class Solution {
public:
    int minBitFlips(int start, int goal) {
        int bits_needed=start^goal;
        int cnt=0;
        while(bits_needed !=0){
            if (bits_needed%2==1){
                cnt++;
            }
            bits_needed=bits_needed/2;

        }
        return cnt;
        
    }
};