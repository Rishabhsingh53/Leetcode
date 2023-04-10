/*
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightview(root,ans,0);
        return ans;
    }
    void rightview(TreeNode* root,vector<int> &arr,int currDepth){
        if(!root){
            return ;
        }
        if(currDepth == arr.size()){
            arr.push_back(root->val);
        }
        rightview(root->right,arr,currDepth+1);
        rightview(root->left,arr,currDepth+1);
    }
};
