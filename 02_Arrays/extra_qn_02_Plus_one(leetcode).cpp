// brute force:  overflow case not handled:

class Solution {
public:
   
    long long convert_to_digits(vector<int> &digits){
        int n = digits.size();
        if (n == 1){
            return digits[0] + 1;
        }
        long long num = 0;
        for (int i = 0; i < n; i++){
            num = num * 10 + digits[i];
        }
        return num + 1;
    }
    
    vector<int> plusOne(vector<int>& digits) {
        
        long long n = convert_to_digits(digits); 
        vector<int> final_arr;
        
        while(n > 0){
            int digit = n % 10;
            final_arr.push_back(digit);
            n = n / 10;
        }
        
        reverse(final_arr.begin(), final_arr.end());
        return final_arr;
    }
};

// optimal solution:

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; 
                return digits; 
            }
            
            digits[i] = 0;
        }
        
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};