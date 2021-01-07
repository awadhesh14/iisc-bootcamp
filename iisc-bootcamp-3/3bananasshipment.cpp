#include<bits/stdc++.h> 

using namespace std; 

// https://www.geeksforgeeks.org/minimum-time-required-to-transport-all-the-boxes-from-source-to-the-destination-under-the-given-constraints/
/*
Binary search on time. For a time T, isPossible checks if it’s possible to deliver all the boxes in time T. 
They do this greedily. 
The trucks and boxes are sorted by weight (smallest to largest). 
We want to have the smaller trucks carrying the smaller boxes and the larger ones carrying a larger box. 
So for each truck, we count how many boxes it can carry in time T, and if the total over all trucks is equal to all boxes then that T is good. 
Otherwise we need a bigger T.

count is the trucks, temp is the current box we’re trying to move

*/


bool isSafe(vector<int> &arr, vector<int> &brr,int n,int m,int time){


    int k=0;//to iterate over boxes
    for(int i=0;i<m && k<n ;i++){
        for(int j=0;j<time && k<n && arr[k]<=brr[i];j+=2){
            k++;
        }
    }
    if(k==n)
        return true;
    return false;

}

int main(){
    //18:15
    int n,m;
    cin>>n>>m;
    vector<int> arr(n),brr(m);
    
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++){
        cin>>brr[i];
        
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    
    int lo = 0,hi = 2*n;
    int mid,ans=0;
    while(lo<=hi){
        mid = (lo+hi)/2;//lo + (hi-lo)/2;

        if(isSafe(arr,brr,n,m,mid)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}