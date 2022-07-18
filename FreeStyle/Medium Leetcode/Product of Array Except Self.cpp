//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int prod = 1;
        ans.push_back(prod);
        for(int i=1; i<n; ++i){
            prod *= nums[i-1];
            ans.push_back(prod);
        }
        
        prod = 1 * nums[n-1];
        for(int i=n-2; i>=0; --i){
            ans[i] *= prod;
            prod *= nums[i];
        }
        
        return ans;
    }
};
