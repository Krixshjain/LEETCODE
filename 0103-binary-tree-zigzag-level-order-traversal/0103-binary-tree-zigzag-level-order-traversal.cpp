// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> result;

//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty()){
//             vector<int> ans;
//             stack<int> qq;
//             int level = q.size();


//             for(int i=0 ; i<level ; i++){
//             TreeNode* curr = q.front();
//             q.pop();

//             if(i%2 == 0){
//                 qq.push(curr->val);
//             }
//             else{
//                 ans.push_back(curr->val);
//             }


//             if(curr->left) q.push(curr->left);
//             if(curr->right) q.push(curr->right);

//             }

            
//             vector<int> temp;
//             int stsize = qq.size();
//             for(int i=0 ; i<stsize ; i++){
//                 temp = temp.push_back(qq.top());
//                 qq.pop();
//             }

            
//             result.push_back(ans);
//             result.push_back(temp);
//         }

//         return result;
//     }
// };



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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);


        bool left_to_right = true;

        while(!q.empty()){
            int levelsize = q.size();

            vector<int> current(levelsize);

            for(int i=0 ; i<levelsize ; i++){
            TreeNode* node = q.front();
            q.pop();

            int index;
            if(left_to_right){
                index = i;
            }
            else{
                index = levelsize - 1 - i;
            }

            current[index] = node->val;


            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            }

            ans.push_back(current);

            left_to_right = !left_to_right;
        }

        return ans;

    }
};