//https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for(int i=0,j=0; i<nums.size(); ++i){
            if(nums[i] == key){
                for(j = max(j, i-k); j <= i+k && j < nums.size(); ++j){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
