// brute force solution: TLE:

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if ((long long)nums[i]>2*(long long)nums[j]){
                    cnt++;

                }
            }
        }
        return cnt;

    }
};

// optimal solution using merge sort:

class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high){
        int left=low;
        int right=mid+1;
        vector<int> temp;
        while(left<=mid && right<=high){
            if (nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
                

            }
            else{
                temp.push_back(nums[right]);
                right++;
            }

        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;

        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for (int i=low; i<=high;i++){
            nums[i]=temp[i-low];
        }

    }

    int merge_sort(vector<int> &nums, int low, int high){
        int cnt=0;
        if (low>=high){
            return cnt;

        }
        int mid=(low+high)/2;
        cnt+=merge_sort(nums, low, mid);
        cnt+=merge_sort(nums, mid+1, high);
        cnt+=count_pairs(nums,low, mid, high);
        merge(nums, low, mid, high);

        return cnt;
    }

    int count_pairs(vector<int> &nums, int low, int mid, int high){
        int cnt=0;
        int right=mid+1;
        for (int i=low;i<=mid; i++){
            while(right<=high && (long long)nums[i]>2*(long long)nums[right]){
                right++;
            }
            cnt+=(right-(mid+1));
        }
        return cnt;

    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return merge_sort(nums,0, n-1);
    }
};