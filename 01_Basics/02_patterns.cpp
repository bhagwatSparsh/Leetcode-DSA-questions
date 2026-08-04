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

void pattern_3(int n){
    for (int i=0;i<n;i++){
        for (int j=i;j>=0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern_3_1(int n){
    for (int i=0;i<n;i++){
        for (int j=n-i-1;j>=0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern_4(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            cout<<j+1;
        }

        for (int j=2*n-2*i-1;j>=0;j--){
            cout<<" ";
        }

        for (int j=i;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }
}

void print_pattern_5(int n){
    for(int i=0;i<=n;i++){
        for (int j=0;j<=n-i-1;j++){
            cout<<"*";
        }

        for (int j=0;j<2*i;j++){
            cout<<" ";
        }
        for(int j=n-i-1;j>=0;j--){
            cout<<"*";
        }
        if(i!=n-1){
            cout<<endl;

        }
        

    }
    for (int i=1;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<"*";
        }
        for (int j=1;j<2*n-2*i-1;j++){
            cout<<" ";
        }
        for (int j=i;j>=0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(){
    // print_pattern(5);
    // print_pattern_2(5);
    // // pattern_3(5);
    // // pattern_3_1(4);
    // pattern_4(5);
    print_pattern_5(5);
    return 0;
}


