#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int, int> map;
    for(int i=0; i<n; ++i){
        map[arr[i]]++;
    }
    int cnt = 0;
    
    if(k == 0){
        for(int i=0; i<n-1; ++i){
            if(map[arr[i]] == 0) continue;
            int temp = map[arr[i]];
            cnt += ((temp * (temp-1))/2);
            map[arr[i]] = 0;
        }
        return cnt;
    }
    
    for(int i=0; i<n-1; ++i){
        if(map[arr[i]] == 0) continue;
        cnt += map[arr[i]] * map[arr[i] - k];
        
        cnt += map[arr[i]] * map[arr[i] + k];
        
        map[arr[i]] = 0;
    }
    
    return cnt;
}
