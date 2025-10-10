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
    int maxDepth(TreeNode* root) {
        
        // Base-case
        if(root==NULL){
            return 0;
        }

        int leftSubTreeHeight = maxDepth(root->left);
        int rightSubTreeHeight = maxDepth(root->right);
        int maxDepth = max(leftSubTreeHeight,rightSubTreeHeight);

        int totalDepth= maxDepth + 1;

        return totalDepth;
    }
};