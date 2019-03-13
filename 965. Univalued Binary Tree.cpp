/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        return(value(root) != -1);
    }
    
    int value(TreeNode* root) // don't call it on a nullptr!
    {
        if (root->left == nullptr)
        {
            if (root->right == nullptr) // leaf
                return( root->val );
            else // Only right child
            {
                int rightval = value(root->right);
                if (rightval == root->val)
                    return(rightval);
                else
                    return(-1);
            }
        }
        else
        {
            if (root->right == nullptr) // left child only
            {
                int leftval = value(root->left);
                if (leftval == root->val)
                    return(leftval);
                else
                    return(-1);
            }
            else // both children
            {
                int leftval = value(root->left);
                int rightval = value(root->right);
                
                if (leftval == rightval && rightval == root->val)
                    return(root->val);
                else
                    return(-1);
            }
        }
    }
};