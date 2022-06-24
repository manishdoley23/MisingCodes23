//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int sum = 0;
        for(int i=1; i<p.size(); ++i){
            sum += max(p[i] - p[i-1], 0);
        }
        return sum;
    }
};
