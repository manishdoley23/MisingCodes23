#include<unordered_map>
int pairSum(int *arr, int n) {
    unordered_map<int, int> umap;
    for(int i=0; i<n; ++i){
        umap[arr[i]]++;
    }
    
    int ans = 0;
    for(int i=0; i<n; ++i){
        int cnt = 0;
        if(umap[arr[i]] && arr[i] != 0){
            cnt = umap[-arr[i]] * umap[arr[i]]; 
            umap[arr[i]] = 0;
            umap[-arr[i]] = 0;
        }
        ans += cnt;
    }
    if(umap[0]){
        ans += umap[0]*(umap[0] - 1)/2;
    }
    
    return ans;
}
