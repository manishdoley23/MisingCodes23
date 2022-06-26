#include<bits/stdc++.h>
using namespace std;

void ksorted(int* arr, int n, int k){
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i=0; i<k; ++i){
        pq.push(arr[i]);
    }

    int j=0;
    for(int i=k; i<n; ++i){
        arr[j] = pq.top();
        pq.pop();
        pq.push(arr[i]);
        j++;
    }

    while(pq.size()){
        arr[j] = pq.top();
        pq.pop();
        j++;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i=0; i<n; ++i) cin >> arr[i];
    ksorted(arr, n, k);
    for(int i=0; i<n; ++i) cout << arr[i] << " ";
}

int main(){
    int T = 1;
    //cin >> T;
    while(T--){
      solve();
    }
}
