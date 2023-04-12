/*
701. Insert into a Binary Search Tree
You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example:
Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
*/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode *curr = root;
        while(true){
            if(curr->val == val){
                break;
            }
            else if(curr->val > val){
                if(!curr->left){
                    curr->left = new TreeNode(val);
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(!curr->right){
                    curr->right = new TreeNode(val);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};
/*
Just search for val in the tree if its present than return the root else insert it into the tree by creating a new object using this val and replace
the null pointer.
*/
