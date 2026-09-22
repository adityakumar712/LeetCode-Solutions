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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == nullptr){
            return res;
        }


        bool lefttoright = 1;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int lvlsize = q.size();
            vector<int>temp(lvlsize);
            int first = 0;
            int last = lvlsize - 1;

            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();

                if(lefttoright == 1){
                    temp[first] = t->val;
                    first++;
                }

                if(lefttoright == 0){
                    temp[last] = t->val;
                    last--;
                }

              

                if(t->left != nullptr){
                    q.push(t->left);
                }

                if(t->right != nullptr){
                    q.push(t->right);
                }
            }

            lefttoright= !lefttoright;
            res.push_back(temp);
        }

        return res;
    }
};