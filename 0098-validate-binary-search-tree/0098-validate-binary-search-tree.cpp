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
// class Solution {
// public:
//     void valid(TreeNode* root , long long floor , long long ceil , bool &check){
//         if(!root) return;
//         if(!check) return;

//         if(root->right && root->left){
//         if(root->left->val < root->val && root->left->val < floor){
//             floor = root->val;
//             check = true;
//             return valid(root->left , floor , ceil , check );
//         }
//         else if(root->right->val > root->val && root->right->val > ceil){
//             ceil = root->val;
//             check = true;
//             return valid(root->right , floor, ceil ,check);
//         }
//         else{
//             check = false;
//         }
//         }
//     }

//     bool isValidBST(TreeNode* root) {
//         if(!root) return true;
//         bool check = true;
//         long long floor = LONG_MAX;
//         long long ceil = LONG_MIN;
//         valid(root,floor , ceil ,check);
//         return check;
//     }
// };


class Solution {
public:
    bool valid(TreeNode* root , long long floor , long long ceil){
        if(!root) return true;
        if(root->val <= floor || root->val >= ceil) return false;

        return valid(root->left , floor , root->val) && valid(root->right , root->val , ceil);

    
    }

    bool isValidBST(TreeNode* root) {
       return valid(root , LONG_MIN , LONG_MAX);
    }
};