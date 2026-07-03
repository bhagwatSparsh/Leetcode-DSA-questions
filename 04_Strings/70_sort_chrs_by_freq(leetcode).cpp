// brute force: close to optimal:
class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        int hash[256]={0};

        for (char ch:s){
            hash[ch]++;
        }

        string new_str="";

        int max_freq=0;
        for (int i=0;i<256;i++){
            if (hash[i]>max_freq){
                max_freq=hash[i];
            }
        }

        for (int freq=max_freq;freq>=0;freq--){
            for (int j=0;j<256;j++){
                if (hash[j]==freq){
                    for (int k=0;k<freq;k++){
                        new_str+=(char)j;
                    }
                }
            }
        }
        return new_str;


    }
};
// optimal soln:
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
   
    static bool comparator(const pair<int, char>& p1, const pair<int, char>& p2) {
        if (p1.first != p2.first) {
            return p1.first > p2.first; 
        }
        return p1.second < p2.second; 
    }

    string frequencySort(string s) {
        
        pair<int, char> freq[256];
        for (int i = 0; i < 256; i++) {
            freq[i] = {0, (char)i}; 
        }
        for (char ch : s) {
            freq[(unsigned char)ch].first++;
        }
        sort(freq, freq + 256, comparator);

     
        string ans = "";
        for (int i = 0; i < 256; i++) {
            if (freq[i].first > 0) {
                // Append the character 'freq[i].second' exactly 'freq[i].first' times
                ans.append(freq[i].first, freq[i].second);
            } else {
                // Since it's sorted descending, as soon as freq is 0, we can stop
                break; 
            }
        }

        return ans;
    }
};
