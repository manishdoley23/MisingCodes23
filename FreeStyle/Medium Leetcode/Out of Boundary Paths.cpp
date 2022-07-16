//https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    int dp[51][51][51];
    int mod = 1000000007;
    
    long paths(int m, int n, int i, int j, int maxMove){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 1;
        }
        
        if(maxMove <= 0){
            return 0;
        }
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        long res = 0;
        res += paths(m, n, i+1, j, maxMove-1);
        res += paths(m, n, i-1, j, maxMove-1);
        res += paths(m, n, i, j+1, maxMove-1);
        res += paths(m, n, i, j-1, maxMove-1);

        return dp[i][j][maxMove] = res % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return paths(m, n, startRow, startColumn, maxMove) % mod;
    }
};
