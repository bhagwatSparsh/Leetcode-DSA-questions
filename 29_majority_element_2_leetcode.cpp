//  brute force solution:


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
           
            if (ans.size() == 0 || 
               (ans.size() == 1 && ans[0] != nums[i]) || 
               (ans.size() == 2 && ans[0] != nums[i] && ans[1] != nums[i])) {
            
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (nums[i] == nums[j]) {
                        cnt++;
                    }
                }
                
                if (cnt > n / 3) {
                    ans.push_back(nums[i]);
                }
                
                if (ans.size() == 2) {
                    break;
                }
            }
        }
        return ans;
    }
};

//better solution using hashing:
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int min_i=int(n/3);
        unordered_map<int,int> mpp;
        for (int i=0;i<n;i++){
            mpp[nums[i]]++;
            if (mpp[nums[i]]==min_i+1){
                ans.push_back(nums[i]);

            }
            if (ans.size()==2){
                break;
            }

        }
        return ans;

    }  
    
};

// optimal solution using Boyer-Moore Voting Algorithm:

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) {
                cnt1++;
            } 
            else if (nums[i] == ele2) {
                cnt2++;
            } 
            else if (cnt1 == 0) {
                ele1 = nums[i];
                cnt1 = 1;
            } 
            else if (cnt2 == 0) {
                ele2 = nums[i];
                cnt2 = 1;
            } 
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) cnt1++;
            else if (nums[i] == ele2) cnt2++; 
        }

   
        vector<int> ls;
        int threshold = n / 3;
        
        if (cnt1 > threshold) ls.push_back(ele1);
        if (cnt2 > threshold) ls.push_back(ele2);

        return ls;
    }
};