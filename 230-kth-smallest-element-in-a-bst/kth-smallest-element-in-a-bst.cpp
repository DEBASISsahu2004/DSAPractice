/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:

    int count = 0, result = 0;

    int kthSmallest(TreeNode* root, int k) {
        traverseInorder(root, k);
        return result;
    }

    void traverseInorder(TreeNode* root, int k){
        if(!root) return;

        traverseInorder(root->left, k);
        count++;
        if(count == k){
            result = root->val;
        }
        traverseInorder(root->right, k);

    }
};