#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


void selection_sort(vector<int> &arr, int n){
    for (int i=0;i<n-1;i++){
        int min_index = i;
        for (int j=i+1;j<n;j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}


void  insertion_sort(vector<int> &arr, int n){
    for (int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }


    }
}


void merge(vector<int> &arr,int low, int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;

        }
        else{
            temp.push_back(arr[right]);
            right++;    
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++; 
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;    
        }

        for (int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }

    }
}

void merge_sort(vector<int>&arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void quickSort(vector<int>& arr, int low, int high) {

        if (low < high) {

            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex - 1);

            quickSort(arr, pivotIndex + 1, high);
        }
    }

int partition(vector<int>& arr, int low, int high) {

        
        int pivot = arr[low];

        int j = low;

        // Move smaller elements to left side
        for (int i = low + 1; i <= high; i++) {

            if (arr[i] < pivot) {

                j++;

                swap(arr[i], arr[j]);
            }
        }

    
        swap(arr[low], arr[j]);

        return j;
}

int main(){
    
    return 0;
}
