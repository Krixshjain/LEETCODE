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
class NodeVal{
    public:
    int minnode, maxnode, sum;

    NodeVal(int minnode , int maxnode , int sum){
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->sum = sum;
    }
};


class Solution {
public:
    
    int globalsum=0;
    
    NodeVal helper(TreeNode* root){
        if(!root) return NodeVal(INT_MAX , INT_MIN , 0);

        auto leftt = helper(root->left);
        auto rightt = helper(root->right);

        if(leftt.maxnode < root->val && root->val < rightt.minnode){
            int currentsum = root->val + leftt.sum + rightt.sum;

            globalsum=max(globalsum,currentsum);

            return NodeVal(min(root->val , leftt.minnode) , max(root->val , rightt.maxnode) , currentsum); 
        }

        return NodeVal(INT_MIN , INT_MAX , 0);
    }



    int maxSumBST(TreeNode* root) {
        globalsum = 0;
        helper(root);
        return globalsum;
    }
};