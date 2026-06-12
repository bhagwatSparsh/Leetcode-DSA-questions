//Brute solution:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            int cnt=0;
            for (int j=0;j<n;j++){
                if (nums[i]==nums[j]){
                    cnt++;
                }

            }
            if (cnt>n/2){
                return nums[i];
            }
        }
        return -1;
        
    }
};

//Beter solution using hashing:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mpp;
        for (int i=0;i<n;i++){
            mpp[nums[i]]++;

        }
        for (auto it:mpp){
            if (it.second> n/2){
                return it.first;
            }
        }
        return -1;
        
    }
};

//optimal solution using Boyer-Moore Voting Algorithm:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ele=0;

        for (int i=0;i<n;i++){
            if (cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ele;
        // int cnt2=0;
        // for (int i=0;i<n;i++){
        //     if (nums[i]==ele){
        //         cnt2++;
        //     }


        // }
        // if (cnt2>n/2){
        //     return ele;
        
        // }
        // return -1;
        
        
    }
    
};
