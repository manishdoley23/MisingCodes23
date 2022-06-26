//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int sum = 0;
        int mx = 0;
        int n = c.size();
        for(int i=0; i<k; ++i){
            mx += c[i];
        }
        sum = mx;
        for(int i=0; i<k; ++i){
            sum = sum + c[n-i-1] - c[k-i-1];
            // cout << n - i - 1 << " " << k - i - 1 << " " << sum << " ";
            mx = max(mx, sum);
        }
        return mx;
    }
};
