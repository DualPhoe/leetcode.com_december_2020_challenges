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
    
    TreeNode * newCurTree = NULL;
    TreeNode * New_Tree = NULL;
    
    void Push( const int & newVal)
    {
        
        if(newCurTree == NULL)
        {
            newCurTree = new TreeNode(newVal);
            
            New_Tree = newCurTree;
            return;
        }
        
        
        newCurTree->right = new TreeNode(newVal);
        newCurTree = newCurTree->right;
    }
    
    void Traverse (TreeNode * oldTree )
    {
        if(!oldTree)
        {
            return;
        }
        Traverse(oldTree->left);

        Push(oldTree->val);
        
        Traverse(oldTree->right);
            
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) 
    {

        newCurTree = New_Tree;
        
        Traverse(root);
        
        return New_Tree;
    }
};
