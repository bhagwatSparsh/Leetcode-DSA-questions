// brute force soln:
class Solution {
public:
    bool is_palindrome(const string &s, int left, int right){
        while(left<right){
            if (s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
    string longestPalindrome(string s) {
        int n=s.size();
        int max_lenP=0;
        
        string res="";
        for (int i=0;i<n;i++){
            for (int j=i;j<n;j++){
                if (is_palindrome(s,i,j)){
                    int current_lenp=j-i+1;

                    if (current_lenp>max_lenP){
                        max_lenP=current_lenp;
                        res=s.substr(i, current_lenp);
                    }
                }

            }
        }
        return res;
        
    }
};

// optimal soln:
class Solution {
public:
    int expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
       
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, max_len = 0;

        for (int i = 0; i < s.size(); i++) {
            
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i + 1);
            
            int current_max = max(len1, len2);
            if (current_max > max_len) {
                max_len = current_max;
                start = i - (current_max - 1) / 2;
            }
        }

        return s.substr(start, max_len);
    }
};
// //class Solution {
// public:
//     bool is_palindrome(const string &s, int left, int right){
//         while(left<right){
//             if (s[left]!=s[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;

//     }
//     string longestPalindrome(string s) {
//         int n=s.size();
//         int max_lenP=0;
        
//         string res="";
//         for (int i=0;i<n;i++){
//             for (int j=i;j<n;j++){
//                 if (is_palindrome(s,i,j)){
//                     int current_lenp=j-i+1;

//                     if (current_lenp>max_lenP){
//                         max_lenP=current_lenp;
//                         res=s.substr(i, current_lenp);
//                     }
//                 }

//             }
//         }
//         return res;
        
//     }
// };