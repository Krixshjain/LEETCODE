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

//     void bst(TreeNode* root , int low,  int high , vector<int> nums){

//         TreeNode* curr = root;


//         if(nums[high] <= curr->val){
//             TreeNode* temp = new Node(nums[high]);
//             curr->left = temp;
//             bst(root, middle , 0 , high--);
//         }
//         else if(nums[high] >= curr->val){
//             TreeNode* temp = new Node(nums[high]);
//             curr->right = temp;
//             bst(root, middle , 0 , high--);
//         }
//     }

//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         int n = nums.size();
//         int middle = n/2;
//         TreeNode* root = new Node(nums[middle]);

//         bst(root , 0 , middle-1 , nums);
//         bst(root , middle+1 , n , nums)
//         return root;

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

    TreeNode* bst(int low,  int high , vector<int> nums){
        if(low>high) return NULL;

        int middle = (low+high)/2;

        TreeNode* root = new TreeNode(nums[middle]);
        root->left = bst(low , middle-1 , nums);
        root->right = bst(middle+1 , high , nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();   
        return bst(0 , n-1 , nums);
    }
};