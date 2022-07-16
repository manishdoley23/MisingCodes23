#include<climits>
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, int> map;
    for(int i=0; i<n; ++i){
        map[arr[i]] = i+1;
    }
    
    
    int maxLen = INT_MIN;
    int start, end;
    vector<int> ans;
    
    int startIndPrev = 0, startIndCurr = 0;
    
    for(int i=0; i<n; ++i){
        if(!map[arr[i]]) continue;
        int len = 1;
        
       	int start = arr[i] + 1;
       	map[arr[i]] = 0;
       	while(map[start]){
       		len++;
            map[start] = 0;
       		start++;
       	}
       	end = start-1;
        
        startIndCurr = i+1;
        
       	start = arr[i]-1;
       	while(map[start]){
       		len++;
            startIndCurr = map[start];
            map[start] = 0;
       		start--;
       	}
       	start = start + 1;

       	if((len > maxLen) || (len == maxLen && startIndCurr < startIndPrev)){
            ans.clear();
       		maxLen = len;
       		ans.push_back(start);
       		ans.push_back(end);
            startIndPrev = startIndCurr;
       	}
    }
    
    return ans;
}
