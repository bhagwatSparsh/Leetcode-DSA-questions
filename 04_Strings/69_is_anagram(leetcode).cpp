// brute force::
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s==t){
            return true;
        }
        return false;
        
    }
};
// better soln:

class Solution {
public:
    
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()){
            return false;

        }
        unordered_map<char, int> mpp;
        for (char ch:  s){
            mpp[ch]++;

        }
        for (char ch: t){
            mpp[ch]--;
            if (mpp[ch]<0){
                return false;
            }
        }
        return true;
        
    }
};

// optimal soln:
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()){
            return false;

        }
        // use frequency array instead of map as data str contn chrs in lower case only. similar data type.
        int freq[26]={0};
        for (int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for (int i=0;i<t.size();i++){
            freq[t[i]-'a']--;
        }
        for (int i=0;i<26;i++){
            if (freq[i]!=0){
                return false;
            }
        }
        return true;
        
    }
};