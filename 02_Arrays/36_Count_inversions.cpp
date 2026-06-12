// bbrute force soln:
class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
    int n=nums.size();
    int cnt=0;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (nums[i]> nums[j]){
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

    int merge(vector<int> nums, int low, int mid, int high){
        int left=low;
        int right=mid+1;
        int cnt=0;
        vector<int> temp;
        while(left<= mid && right<=high){
            if (nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                cnt+=(mid-left+1);
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
        for (int i=low;i<high;i++){
            nums[i]=temp[i-low];
            
        }
        return cnt;
    }
   int merge_sort(vector<int> nums, int low, int high){
    int cnt=0;
    if (low>=high){
        return cnt;
    }
    int mid=(low+high)/2;
    cnt+=merge_sort(nums, low, mid);
    cnt+=merge_sort(nums, mid+1, high);
    cnt+=merge(nums, low, mid, high);

    return cnt;
   }
   long long int numberOfInversions(vector<int> nums) {
    int n=nums.size();
    return merge_sort(nums, 0, n-1);
   


    }
};
