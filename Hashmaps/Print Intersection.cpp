#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> umap;
    for(int i=0; i<n; ++i){
        umap[arr1[i]]++;
    }
    for(int i=0; i<m; ++i){
        if(umap[arr2[i]]){
            cout << arr2[i] << endl;
            umap[arr2[i]]--;
        }
    }
}
