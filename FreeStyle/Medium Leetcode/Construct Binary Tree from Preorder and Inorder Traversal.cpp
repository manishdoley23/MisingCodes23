//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(inStart > inEnd) return NULL;
        
        int rootInd;
        for(int i=inStart; i<=inEnd; ++i){
            if(inorder[i] == preorder[preStart]){
                rootInd = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        root-> left = buildTreeHelp(preorder, inorder, preStart+1, rootInd - inStart + preStart, inStart, rootInd - 1);
        root-> right = buildTreeHelp(preorder, inorder, rootInd - inStart + preStart + 1, preEnd, rootInd + 1, inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelp(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
