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
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        
        if(root == NULL) return width;

        queue<pair<TreeNode* , long>> q;
        
        q.push({root,0});

        



        while(!q.empty()){
            int size = q.size();

            long minIdx = q.front().second; 

            long first = 0;
            long last = 0;

            for(int i=0 ; i<size ; i++){
                long currIdx = q.front().second - minIdx;
                TreeNode* node =q.front().first;


                q.pop();

                if(i==0) first = currIdx;
                if(i== size-1) last = currIdx;

                if(node->left != NULL) q.push({node->left , 2 * currIdx + 1});
                if(node->right != NULL) q.push({node->right , 2 * currIdx + 2});

            }

            width = max(width , static_cast<int>(last-first+1));

        }
        return width;
    }
};