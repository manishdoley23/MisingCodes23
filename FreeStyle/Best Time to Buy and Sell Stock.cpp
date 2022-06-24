//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int minInd = 0;
        int maxInd = 0;
        int i = 0;
        int mx = INT_MIN;
        int sum = 0;
        while(i < p.size()){
            if(p[i] > p[maxInd]){
                maxInd = i;
            }
            if(p[i] < p[minInd]){
                minInd = i;
                if(maxInd < i){
                    maxInd = i;
                }
            }
            sum = p[maxInd] - p[minInd];
            mx = max(sum, mx);
            i++; 
        }
        return mx;
    }
};
