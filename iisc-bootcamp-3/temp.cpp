// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

int pairsUnder(vector<int>& nums, int m) {
    int j = 0, res = 0;
    for (auto i = 0; i < nums.size(); ++i) {
        while (j < nums.size() && nums[j] - nums[i] <= m)
            ++j;
        res += j - i - 1;
    }
    return res;
}

int smallestDistancePair(vector<int>& nums, int k) {
    sort(begin(nums), end(nums));
    int l = 0, h = 1000000;
    while (l < h) {
        int m = (l + h) / 2;
        if (k <= pairsUnder(nums, m))
            h = m;
        else
            l = m + 1;
    }
    return l;
}

int main() 
{ 
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<smallestDistancePair(arr,k)<<endl;
	return 0; 
} 
