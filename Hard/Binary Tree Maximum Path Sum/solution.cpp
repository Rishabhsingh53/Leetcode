/*
124. Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root,maxi);
        return maxi;
    }

    int maxPath(TreeNode* root,int &maxi){
        if(!root){
            return 0;
        }
        int l = max(0,maxPath(root->left,maxi));
        int r = max(0,maxPath(root->right,maxi));
        maxi = max(maxi,l+r+root->val);
        return max(l,r) + root->val;
    }
};
