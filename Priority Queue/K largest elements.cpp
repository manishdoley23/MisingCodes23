#include<queue>
vector<int> kLargest(int arr[], int n, int k){
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; ++i){
        pq.push(arr[i]);
    }
    for(int i=k; i<n; ++i){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(pq.size()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
