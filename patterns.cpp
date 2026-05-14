#include<bits/stdc++.h>
using namespace std;

void print_pattern(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<=n-i+1;j++){
            cout<<" ";
        }
        for (int j=0;j<2*i+1;j++){
            cout<<"*";
        }

        for (int j=0;j<=n-i+1;j++){
            cout<<" ";
        }

        cout<<endl;
    }

}

void print_pattern_2(int n){

    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<" ";

        }
        for (int j=n-i-1;j>=0;j--){
            cout<<"*";
        }
        for (int j=n-i-1;j>=1;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    // print_pattern(5);
    print_pattern_2(5);
    return 0;
}