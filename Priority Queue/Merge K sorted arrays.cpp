#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> arr) {
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<arr.size(); ++i){
        for(int j=0; j<arr[i]-> size(); ++j){
            pq.push(arr[i]->at(j));
        }
    }
    vector<int> ans;
    while(pq.size()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
