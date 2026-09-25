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
    TreeNode* fun(TreeNode* root , int k){
        if(root == nullptr){
            return nullptr;
        }

        if(root->val == k){
            return root;
        }

        if(root->val > k){
            return fun(root->left , k);
        }else{
            return fun(root->right , k);
        }

      
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return fun(root , val);
    }
};