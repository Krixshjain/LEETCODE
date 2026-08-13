/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL) s.append("null,");
            else{
                s.append(to_string(curr->val)+',');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data); //converts the string into input data => name of this is ss
        string value;

        getline(ss,value,','); // will iterate one by one
        TreeNode* root = new TreeNode(stoi(value)); // stoi makes it integer
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            getline(ss,value,',');

            if(value != "null"){
                curr->left = new TreeNode(stoi(value));
                q.push(curr->left);
            }

            getline(ss,value,',');

            if(value != "null"){
                curr->right = new TreeNode(stoi(value));
                q.push(curr->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));