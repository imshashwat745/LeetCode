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
private:
    #define data val
    int ans;
    int help(TreeNode* root){
        if(root==NULL)return 0;
        int l=help(root->left);
        int r=help(root->right);
        ans=max(ans,l+r+root->data);
        ans=max(ans,root->data);
        ans=max(ans,l+root->data);
        ans=max(ans,r+root->data);
        return max(l+root->data,max(r+root->data,max(root->data,0)));
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)return 0;
        ans=root->data;
        help(root);
        return ans;
    }
};