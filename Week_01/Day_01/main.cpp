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
    int maxDepth(TreeNode* root) 
    {
        if (!root)
        {
            return 0;
        }
        int res =0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        if(left > right)
        {
            res = left;
        }
        else
        {
            res = right;
        }
        
        return res+1;
        
    }
};
