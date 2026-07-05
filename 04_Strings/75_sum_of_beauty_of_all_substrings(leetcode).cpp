// brute force:
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total_beauty = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
               
                freq[s[j] - 'a']++;
                int max_freq = 0;
                int min_freq = 500; 

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) { 
                        max_freq = max(max_freq, freq[k]);
                        min_freq = min(min_freq, freq[k]);
                    }
                }

                total_beauty += (max_freq - min_freq);
            }
        }

        return total_beauty;
    }
};

// optimal:
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total_beauty = 0;
        for (int i = 0; i < n; i++) {
            // using rolling frequency array function:
            //O(n2*26)
            int freq[26] = {0};

            for (int j = i; j < n; j++) {
               
                freq[s[j] - 'a']++;
                int max_freq = 0;
                int min_freq = 500; 

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) { 
                        max_freq = max(max_freq, freq[k]);
                        min_freq = min(min_freq, freq[k]);
                    }
                }

                total_beauty += (max_freq - min_freq);
            }
        }

        return total_beauty;
    }
};