//https://leetcode.com/problems/range-sum-of-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sum(TreeNode *root, int low, int high, int &ans){
        if(root == NULL) return;
        if(root-> val <= high && root-> val >= low){
            // sum(root-> left, low, high, ans);
            ans += root-> val;
            //cout << root-> val << " ";
            // sum(root-> right, low, high, ans);
            // ans += root-> val;
        }
        if(root-> val > low){
            sum(root-> left, low, high, ans);
        }
        if(root-> val < high){
            sum(root-> right, low, high, ans);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        sum(root, low, high, ans);
        return ans;
    }
};
