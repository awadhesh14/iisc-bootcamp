#include<bits/stdc++.h> 


// https://www.geeksforgeeks.org/k-th-smallest-absolute-difference-two-elements-array/

//https://leetcode.com/problems/find-k-th-smallest-pair-distance/

using namespace std; 

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    
    int lo= 0;
    int hi = nums[nums.size()-1] - nums[0];
    int n = nums.size();
    while(lo<hi){
        int mi  = (lo+hi)/2;
        int count = 0, left = 0;
        for(int right = 0;right<n; right++){
            while (nums[right] - nums[left] > mi) left++;
            count += right - left;
        }
        if (count >= k) hi = mi;
        else lo = mi + 1;         
    }
    return lo;
}
int smallestDistancePair2(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    
    int lo= 0;
    int hi = nums[nums.size()-1] - nums[0];
    int n = nums.size();
    int mi,count;
    while(lo<hi){
        mi  = (lo+hi)/2;
        count = 0;
        /*for(int right = 0;right<n; right++){
            while (nums[right] - nums[left] > mi) left++;
            count += right - left;
        }*/
        for(int i=0;i<n;i++){
            count += upper_bound(nums.begin()+i,nums.end(),nums[i]+mi) - (nums.begin()+i+1);
        }
        if (count >= k) hi = mi;
        else lo = mi + 1;         
    }
    return lo;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<smallestDistancePair(arr,k)<<endl;
}

/*int search(vector<int> arr,int mid){
    int t = 0;
    for(int i=0;i<arr.size();i++){
        t+= upper_bound(arr.begin()+i, arr.end(), arr[i]+mid) - (arr.begin()+i+1);
    }
    return t;
}
int main() 
{ 
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr.begin(), arr.end());
    

    int hi = arr[arr.size()-1] - arr[0];
    int lo = arr[1]-arr[0];
    for(int i=1;i<arr.size();i++){
        lo = min(lo,arr[i]-arr[i-1]);
    }
    int mid,ans;

    while(lo<hi){
        mid = lo + (hi-lo)/2;

        if(search(arr,mid)<=    k){ // number of pairs with absolute difference <= mid
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    cout<<mid<<endl;
	return 0; 
} */
