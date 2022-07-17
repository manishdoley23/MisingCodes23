#include<unordered_map>
#include<climits>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> map;
    int sum = 0;
    int maxLen = INT_MIN;
    int len;
    for(int i=0; i<n; ++i){
    	sum += arr[i];

    	if(sum == 0){
    		len = i+1;
    		maxLen = max(len, maxLen);
    		continue;
    	}

    	if(map[sum]){
    		len = (i+1) - map[sum];
    		maxLen = max(len, maxLen);
    		continue;
    	}
    	map[sum] = i+1;
    }
    return maxLen;
}
