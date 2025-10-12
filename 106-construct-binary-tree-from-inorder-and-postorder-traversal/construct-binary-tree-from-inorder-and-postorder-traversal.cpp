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
    void createMapping(vector<int> inorder, unordered_map<int,int> &valMap)
    {
       for(int i=0;i<inorder.size();i++)
       {
          int element = inorder[i];
          int index = i;
          valMap[element]=index;
       }
    }


    TreeNode* constructTree(unordered_map<int,int> &valMap,vector<int> postorder,vector<int> inorder, int &postorderIndex, int inorderStart, int inorderEnd)
    {
        //base-case
        if(postorderIndex<0){
            return NULL;
        }

        if(inorderStart > inorderEnd){
            return NULL;
        }

        // Step - 01:
        int element = postorder[postorderIndex];
        postorderIndex--;

        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder = valMap[element];

        root->right = constructTree(valMap,postorder,inorder,postorderIndex,elementIndexInsideInorder+1,inorderEnd);
        root->left = constructTree(valMap,postorder,inorder,postorderIndex,inorderStart,elementIndexInsideInorder-1);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int postorderIndex = postorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;

        unordered_map<int,int> valMap;
        createMapping(inorder,valMap);

        TreeNode* root = constructTree(valMap,postorder,inorder,postorderIndex,inorderStart,inorderEnd);

        return root;
    }
};