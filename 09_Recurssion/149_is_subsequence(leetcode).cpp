// two pointer approach:
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.length() && j<t.length()){
            if (s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.length();
    }
};

// recurssion approach:
// take auxilliary space comp:
#include <string>

using namespace std;

class Solution {
public:
    bool helper(int i, int j, const string& s, const string& t) {
        if (i == s.length()) return true;
        if (j == t.length()) return false;

        if (s[i] == t[j]) {
            return helper(i + 1, j + 1, s, t);
        }

        return helper(i, j + 1, s, t);
    }

    bool isSubsequence(string s, string t) {
        return helper(0, 0, s, t);
    }
};