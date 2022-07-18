//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; ++i){
            for(int j=1; j<m; ++j){
                mat[i][j] += mat[i][j-1]; 
            }
        }

        int ans = 0;

        unordered_map<int, int> map;
        for(int start=0; start<m; ++start){
            for(int end=start; end<m; ++end){
                map.clear();
                map[0]++;

                int sum = 0;

                for(int i=0; i<n; ++i){
                    int curr = mat[i][end];

                    if(start > 0){
                        curr -= mat[i][start-1]; 
                    }

                    sum += curr;

                    ans += map[sum - target];

                    map[sum]++;
                }
            }
        }

        return ans;
    }
};
