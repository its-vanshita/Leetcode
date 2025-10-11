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
    bool solve(TreeNode* root, int targetSum, int sum){

        //base-case
        if(root==NULL){
            return false;
        }

        // root NULL nahi hai
        sum = sum + root->val;

        // agar root leaf node hai
        if(root->left==NULL && root->right==NULL)
        {
            if(sum == targetSum)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        bool leftAns = solve(root->left,targetSum,sum);
        bool rightAns = solve(root->right,targetSum,sum);


        if(leftAns==false && rightAns==false){
            return false;
        }

        else if(leftAns==true && rightAns==false){
            return true;
        }

        else if(leftAns==false && rightAns==true){
            return true;
        }

        else{
            // leftAns==true && rightAns==true
            return true;
        }
    }



    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        bool ans = solve(root,targetSum,sum);
        return ans;
    }
};