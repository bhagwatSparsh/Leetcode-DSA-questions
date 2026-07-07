#include <string>

class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;

        string num = std::to_string(n);
        string x_str = "";
        long long sum = 0; 

        for (char ch : num) {
            if (ch != '0' && ch != '-') {
                x_str += ch;
                sum += (ch - '0'); 
            }
        }
        if (x_str.empty()) return 0;
        long long x_int = std::stoll(x_str); // Use stoll for long long
        
        return (x_int * sum);
    }
};