//https://www.codechef.com/problems/KCON

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadanes(int* arr, int n){
	ll sum = 0;
	ll maxSum = INT_MIN;
	for(int i=0; i<n; ++i){
		sum += arr[i];
		maxSum = max(maxSum, sum);
		if(sum < 0) sum = 0;
	}
	return maxSum;
}

ll solve(int* arr, int n, int k){

	ll kadanesSum = kadanes(arr, n);
	if(k == 1){
		return kadanesSum;
	}

	ll prefSum = 0, suffSum = 0;
	ll maxPrefSum = INT_MIN, maxSuffSum = INT_MIN;

	for(int i=0; i<n; ++i){
		prefSum += arr[i];
		maxPrefSum = max(maxPrefSum, prefSum);
	}

	ll totSum = prefSum;

	for(int i=n-1; i>=0; --i){
		suffSum += arr[i];
		maxSuffSum = max(maxSuffSum, suffSum);
	}

	ll ans;
	if(totSum < 0){
		ans = max(maxPrefSum + maxSuffSum, kadanesSum);
	}else{
		ans = max(maxPrefSum + maxSuffSum + (totSum * (k-2)), kadanesSum);
	}

	return ans;
}

void solve(){
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i=0; i<n; ++i) cin >> arr[i];

	cout << solve(arr, n, k) << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
      solve();
    }
}
