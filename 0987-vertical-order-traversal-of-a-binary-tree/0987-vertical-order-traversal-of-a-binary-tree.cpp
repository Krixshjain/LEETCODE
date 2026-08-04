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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        map<int , map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int col = current.second.first;
            int row = current.second.second;

            nodes[col][row].insert(node->val);

            if(node->left) q.push({node->left , {col-1 , row+1}});
            if(node->right) q.push({node->right , {col+1 , row+1}});

        }
            for(auto& [col,rowMap] : nodes){
                vector<int> colNodes;

                for(auto& [row , values] : rowMap){
                    colNodes.insert(colNodes.end() , values.begin() , values.end());
                }

                ans.push_back(colNodes);
            }
            return ans;
    }
};