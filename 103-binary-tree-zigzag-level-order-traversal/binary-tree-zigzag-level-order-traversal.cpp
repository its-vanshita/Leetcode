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
    void reverseVector(vector<int> &arr){
        int start=0;
        int end=arr.size()-1;

        while(start<end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        if(root==NULL){
            return ans;
        }

        q.push(root);
        bool leftToRight=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
              TreeNode* front = q.front();
              q.pop();

              level.push_back(front->val);

              if(front->left!=NULL){
                q.push(front->left);
              }

              if(front->right!=NULL){
                q.push(front->right);
              }
            }
            
            if(!leftToRight)
               reverseVector(level);
            ans.push_back(level);
            leftToRight = !leftToRight;  
        }
        return ans;
    }
};