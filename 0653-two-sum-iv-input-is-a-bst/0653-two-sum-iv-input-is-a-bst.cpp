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

    // Get next smallest element
    int getSmall(stack<TreeNode*>& st) {

        TreeNode* node = st.top();
        st.pop();

        int value = node->val;

        // Go to right subtree
        node = node->right;

        // Then go as left as possible
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }

        return value;
    }


    // Get next largest element
    int getLarge(stack<TreeNode*>& st) {

        TreeNode* node = st.top();
        st.pop();

        int value = node->val;

        // Go to left subtree
        node = node->left;

        // Then go as right as possible
        while (node != NULL) {
            st.push(node);
            node = node->right;
        }

        return value;
    }


    bool findTarget(TreeNode* root, int k) {

        if (root == NULL) {
            return false;
        }

        stack<TreeNode*> asc;
        stack<TreeNode*> desc;


        // Prepare ascending stack
        TreeNode* node = root;

        while (node != NULL) {
            asc.push(node);
            node = node->left;
        }


        // Prepare descending stack
        node = root;

        while (node != NULL) {
            desc.push(node);
            node = node->right;
        }


        // Get first smallest and first largest
        int small = getSmall(asc);
        int large = getLarge(desc);


        // Two pointer
        while (small < large) {

            int sum = small + large;

            if (sum == k) {
                return true;
            }

            else if (sum < k) {
                small = getSmall(asc);
            }

            else {
                large = getLarge(desc);
            }
        }

        return false;
    }
};