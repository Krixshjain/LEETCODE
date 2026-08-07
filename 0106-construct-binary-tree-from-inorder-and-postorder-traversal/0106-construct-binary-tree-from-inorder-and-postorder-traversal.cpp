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
    TreeNode* buildmap(vector<int>& postorder , int& postindex , vector<int>& inorder, int instart , int inend , unordered_map<int,int>& inmap){
        

        if(instart>inend) return NULL;

        int rootval = postorder[postindex--];
        TreeNode* root = new TreeNode(rootval);

        int inroot = inmap[rootval];

        root->right = buildmap(postorder , postindex , inorder , inroot+1 , inend , inmap);
        root->left = buildmap(postorder , postindex , inorder,instart, inroot-1 , inmap);

        return root;
    }




    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inmap;

        for(int i=0 ; i<inorder.size() ; i++){
            inmap[inorder[i]] = i;
        }
        int postindex = postorder.size()-1;
        TreeNode* root = buildmap(postorder , postindex , inorder , 0 , inorder.size()-1 , inmap);

        return root;
    }
};