#include<bits/stdc++.h> 

// https://www.hackerrank.com/contests/iisc-3/

using namespace std; 

long long int  f(long long int n){
    if(n&1) return 0;
    return 1+f(n/2);
}

int main(){

    long long int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<f(k)+1<<endl;
    }
    return 0;
}

// simple google search and oasis will give you the formulae