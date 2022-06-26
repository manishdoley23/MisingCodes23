#include<queue>
bool helper(int* arr, int n, int p){
    if(p > n){
        return 1;
    }
    int c1, c2;
    c1 = 2 * p + 1;
    c2 = 2 * p + 2;
    if(c1 > n) return 1;
    else if(c2 > n){
        if(arr[p] < arr[c1]) return 0;
    }else if(arr[p] < arr[c1] || arr[p] < arr[c2]){
        return 0;
    }
    
    bool left = helper(arr, n, c1);
    bool right = helper(arr, n, c2);
    
    return left && right;
}

bool isMaxHeap(int arr[], int n) {
	return helper(arr, n, 0);
}
