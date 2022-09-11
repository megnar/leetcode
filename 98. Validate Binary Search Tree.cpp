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
    bool isvalid(TreeNode* root, long long minn, long long maxx){
        if (root == NULL){
            return true; 
        }
        if (root->val < maxx && root->val > minn){
            return isvalid(root->left, minn, root->val) && isvalid(root->right, root->val, maxx);
        }
        else{
            return false; 
        }
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root, -3147483647, 3147483647);
    }
};
