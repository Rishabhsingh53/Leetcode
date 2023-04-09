/*
103. Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n=1;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int level = q.size();
            vector<int> arr;
            while(level--){
                TreeNode* temp = q.front();
                q.pop();
                arr.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            n++;
            if(n%2){
                reverse(arr.begin(),arr.end());
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
// refer level order traversal in binary tree
