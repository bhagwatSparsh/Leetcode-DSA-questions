// brute force soln:

class Solution {
public:
    string left_shift(string s, int i){
        int len=s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+i);
        reverse(s.begin()+i, s.end());

        return s;
    }

    bool rotateString(string s, string goal) {
        int n=s.size();
        string res="";
        for (int i=0;i<n;i++){
            res=left_shift(s,i);
            if (res==goal){
                return true;
            }

        }
        return false;
        
    }
};

// optimal soln:

class Solution {
public:
    bool rotateString(string s, string goal) {
        int len=s.size();
        int len_goal=goal.size();
        if (len!=len_goal){
            return false;
        }

        string doubled=s+s;
        return doubled.contains(goal);

        
    }
};