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

    int calculate(TreeNode* root , int& maxdia){
        if(root == NULL) return 0;

        int leftnode = calculate(root->left , maxdia);
        int rightnode = calculate(root->right , maxdia);

        maxdia = max(maxdia , leftnode + rightnode);
        

        return 1 + max(rightnode , leftnode);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia = 0;
        calculate(root , maxdia);
        return maxdia;
    }
};