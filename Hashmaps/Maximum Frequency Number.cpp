#include<unordered_map>
int highestFrequency(int arr[], int n) {
    unordered_map<int, int> umap;
    int cnt = 0, ans = 0;
    for(int i=0; i<n; ++i){
        umap[arr[i]]++;
    }
    
    for(int i=0; i<n; ++i){
        if(umap[arr[i]] > cnt){
            cnt = umap[arr[i]];
            ans = arr[i];
        }
    }
    
    return ans;
}
