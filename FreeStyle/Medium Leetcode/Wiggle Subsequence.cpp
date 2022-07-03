//https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int high=1, low=1;
        int n = nums.size();
        for(int i=1; i<n; ++i){
            if(nums[i] > nums[i-1]) high = low+1;
            else if(nums[i] < nums[i-1]) low = high+1;
        }
        return max(high, low);
    }
};
