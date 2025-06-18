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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, 0, limit);
    }

    TreeNode* dfs(TreeNode* root, int sum, int limit){
        if(root == nullptr) return root;

        // if root node is found
        if(root->left == nullptr && root->right == nullptr){
            if(sum + root->val >= limit) return root;
            else return nullptr;
        }

        // iterating to each level and finding the sum
        root->left = dfs(root->left, sum + root->val, limit);
        root->right = dfs(root->right, sum + root->val, limit);

        if(root->left == nullptr && root->right == nullptr){
            return nullptr;
        }else{
            return root;
        }
    }
};