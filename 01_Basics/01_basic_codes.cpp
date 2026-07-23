#include<bits/stdc++.h>
using namespace std;

void print_name(string name){
    cout<<"My name is "<<name<<endl;
    
}


int main(){
    string name;
    
    cout<<"Enter your full name: ";

    getline(cin,name);
    print_name(name);
    return 0;
}

int find_larg(int arr[], int n){
    int largest=-10000;

    for (int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }

    }
    return largest;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n ; i++)
    {
        cin>>arr[i];
    }
    int largest = find_larg(arr, n);
    cout<<"The largest element in the array is: "<<largest<<endl;


}

