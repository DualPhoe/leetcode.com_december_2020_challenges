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
class BSTIterator {
    vector<int> my_list;
    int count =0;
    void Traverse(TreeNode * root)
    {
        if(!root)
        {
            return;
        }
        Traverse(root->left);
        my_list.push_back(root->val);
        Traverse(root->right);
    }
public:
    BSTIterator(TreeNode* root) 
    {
        Traverse(root);
        
    }
    
    int next() 
    {
        int res = my_list[count];
        count ++;
        return res;
    }
    
    bool hasNext() 
    {
        if(count < my_list.size())
        {
            return true;
        }
        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
