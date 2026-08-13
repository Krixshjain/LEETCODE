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
    void leftmost(TreeNode* root , stack<TreeNode*>& leftt){
        while(root){
            leftt.push(root);
            root = root->left;
        }
    }

    void rightmost(TreeNode* root, stack<TreeNode*>& rightt){
        while(root){
            rightt.push(root);
            root = root->right;
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        stack<TreeNode*> leftt;
        stack<TreeNode*> rightt;

        leftmost(root, leftt);
        rightmost(root , rightt);

        while(!leftt.empty() &&  !rightt.empty()){
            TreeNode* leftpt = leftt.top();
            TreeNode* rightpt = rightt.top();

            if(leftpt == rightpt) break;

            int currentsum = leftpt->val + rightpt->val;

            if(currentsum == k) return true;
            else if(currentsum < k){
                leftt.pop();
                leftmost(leftpt->right , leftt);
            } 
            else{
                rightt.pop();
                rightmost(rightpt->left , rightt);
            }
        }

        return false;

    }
};