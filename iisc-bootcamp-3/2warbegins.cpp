#include<bits/stdc++.h> 

using namespace std; 

int main(){


	int t,n,k;
	cin>>t;
	vector<pair<int,int> > tvec;
	vector<int> arr,brr;
	vector<long long int> ans;
	auto comp = []( pair<int,int> a, pair<int,int> b ) { return a.second > b.second; };
	
	while(t--){
		cin>>n>>k;
		arr.resize(n);
		brr.resize(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
			cin>>brr[i];
		vector<pair<pair<int,int>,int> > crr(n);
		ans.resize(n);
		for(int i=0;i<n;i++)
			crr[i] = {{arr[i],brr[i]},i};
		sort(crr.begin(),crr.end());
		
		
		priority_queue<pair<int,int> ,vector<pair<int,int> >, decltype( comp ) > pq( comp );
		/*for(int i=0;i<n;i++)
			pq.push({arr[i],-brr[i]});
		for(int i=0;i<n;i++)
			{cout<<(pq.top().first)<<endl; pq.pop();}
		for(int i=0;i<n;i++)
			cout<<crr[i].first<<" "<<crr[i].second<<endl;*/
		// tvec.clear();
		long long int cur=0,tmp=0;
		for(int i=0;i<n;i++){
			tmp=0;
			if(pq.empty() && k>0){
				cur+=crr[i].first.second;
				pq.push(crr[i].first);
			}
			else if((int)pq.size()<k){
				cur+=crr[i].first.second;
				pq.push(crr[i].first);
			}
			else if(!pq.empty() && (int)pq.size()==k && pq.top().second<crr[i].first.second){
				cur -= pq.top().second;
				tmp = pq.top().second;
				pq.pop();
				pq.push(crr[i].first);
				cur+=crr[i].first.second;
			}
			else{
				// cur = pq.top().second;
				tmp = crr[i].first.second;
			}
			ans[crr[i].second] = cur+tmp;
			// cout<<cur+tmp<<" ";
		}
		for(long long int it:ans)
			cout<<it<<" ";
		cout<<endl;
		/*while(!pq.empty()){
			cout<<pq.top().first<<" "<<pq.top().second<<endl;
			pq.pop();
		}*/
		
	}

	return 0;
}

