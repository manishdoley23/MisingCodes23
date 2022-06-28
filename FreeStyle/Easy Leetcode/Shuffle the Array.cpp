//https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i=0, j=n;
        bool b = 1;
        while(j<nums.size()){
            if(b){
                ans.push_back(nums[i]);
                i++;
                b = 0;
            }else{
                ans.push_back(nums[j]);
                j = i+n;
                b = 1;
            }
        }
        return ans;
    }
};
