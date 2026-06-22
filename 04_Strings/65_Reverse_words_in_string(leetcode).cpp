// brute force soln:

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i=0;
        int n=s.size();
        while(i<n){
            while(i<n && s[i]== ' ' ){
                i++;
            }
            if (i>=n){
                break;
            }

            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
                

            }
            // push only after entire word is in word.
            words.push_back(word);
            

        }
        reverse(words.begin(), words.end());
        string ans="";
        for (int i=0;i<words.size();i++){
            ans+=words[i];
            if (i!=words.size()-1){
                ans+=' ';
            }
        }
        return ans;
        
    }
};

// optimal soln:

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        reverse(s.begin(), s.end());
        
        for (int i = 0; i < n; i++) {
            
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) {
                break;
            }
            string word = "";
            while (i < n && s[i]!= ' ') {
                word += s[i];
                i++; 
            }
            // reverse the word extracted to original word
            reverse(word.begin(), word.end());
       
            if (ans.size() > 0) {
                ans += " " + word;
            } else {
                ans += word;
            }
            
            // Crucial: The outer for-loop has an i++, but our inner loop 
            // leaves 'i' sitting right on a space (or at the end). 
            // We decrement 'i' here so the for-loop's 'i++' puts us exactly where we need to be.
            i--; 
        }
        return ans;
    }
};