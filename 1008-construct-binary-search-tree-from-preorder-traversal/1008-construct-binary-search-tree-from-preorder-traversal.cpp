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
    TreeNode* build(vector<int>& preorder , int &i , int bound){
        if(i == preorder.size() || preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder , i , root->val); // when we are going left at that time we are passing the same value as left is lesser value so always we want value less that current;
        root->right = build(preorder, i , bound); // in right we are taking the prev bound that was there when baccktarcking;
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder , i , INT_MAX);
    }
};