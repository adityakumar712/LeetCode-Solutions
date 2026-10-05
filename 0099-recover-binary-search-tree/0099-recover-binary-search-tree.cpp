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
      int glt =0 ;
      TreeNode* glt1first = nullptr;
      TreeNode* glt1second = nullptr;
      TreeNode* glt2first = nullptr;
      TreeNode* glt2second = nullptr;
      TreeNode* prev = nullptr;

      void inord(TreeNode* root){
        if(root == nullptr){
            return;
        }

        inord(root->left);

        if(prev == nullptr){
            prev = root;
        }

        else{
            if(root->val < prev->val){
                if(glt == 0){
                    glt1first = prev;
                    glt1second = root;
                    glt++;
                }else{
                    glt2first = prev;
                    glt2second = root;
                    glt++;
                }
            }

            prev = root;
            
        }

        inord(root->right);
      }

    void recoverTree(TreeNode* root) {
        inord(root);

        if(glt == 1){
            swap(glt1first->val , glt1second->val);
        }else{
            swap(glt1first->val , glt2second->val);
        }
    }
};