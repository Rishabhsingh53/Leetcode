/*
102. Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
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
            ans.push_back(arr);
        }
        return ans;
    }
};
/*
In this implementation, we first create an empty vector ans to store the result of the level order traversal. 
We then check if the root of the tree is null. If it is, we return the empty ans vector.
We create a queue of tree nodes and push the root node into it. 
We then start a while loop that runs as long as the queue is not empty. 
At each iteration of the loop, we get the size of the queue and 
create a new vector arr to store the values of the nodes at the current level. 
We then iterate over the nodes at the current level and add their values to the arr vector. 
We also add any children of these nodes to the queue if they exist.
After we've processed all the nodes at the current level, we add the arr vector of values to the ans vector of vectors. 
We repeat this process until we've processed all the levels of the tree.
Finally, we return the ans vector of vectors, which contains the level order traversal of the binary tree.
*/
