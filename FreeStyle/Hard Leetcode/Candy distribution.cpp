//https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> leftToRight(n, 1);
        for(int i=1; i<n; ++i){
            if(ratings[i] > ratings[i-1]){
                leftToRight[i] = leftToRight[i-1] + 1;
            }
        }
        // for(int i=0; i<n; ++i) cout << leftToRight[i] << " ";
        // cout << endl;
        vector<int> mx(n, 1);
        int sum = leftToRight[n-1];
        for(int i=n-2; i>=0; --i){
            // cout << "i: " << i << " " << leftToRight[i] << " " << mx[i] << endl;
            if(ratings[i] > ratings[i+1]){
                mx[i] = mx[i+1] + 1;
            }
            sum += max(mx[i], leftToRight[i]);
        }
        // for(int i=0; i<n; ++i) cout << mx[i] << " ";
        return sum;
    }
};
