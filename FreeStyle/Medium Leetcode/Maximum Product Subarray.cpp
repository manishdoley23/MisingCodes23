//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& n) {
    	if(n.size() == 0) return 0;

    	int maxHerePre = n[0];
    	int minHerePre = n[0];
    	int maxSoFar = n[0];
    	int maxHere, minHere;

    	for(int i=1; i<n.size(); ++i){
    		maxHere = max(max(maxHerePre * n[i], minHerePre * n[i]), n[i]);
    		minHere = min(min(maxHerePre * n[i], minHerePre * n[i]), n[i]);

    		maxSoFar = max(maxHere, maxSoFar);
    		maxHerePre = maxHere;
    		minHerePre = minHere;
    	}
    	return maxSoFar;
    }
};
