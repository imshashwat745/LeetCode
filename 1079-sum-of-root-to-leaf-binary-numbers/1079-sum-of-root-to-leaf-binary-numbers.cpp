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
    int findNum(string &curr){
        reverse(curr.begin(),curr.end());
        int ans=0;
        for(int i=0;i<curr.size();++i){
            if(curr[i]=='0') continue;
            ans|=(1<<i);
        }
        reverse(curr.begin(),curr.end());
        return ans;
    }
    int help(TreeNode* root,string &curr,int i){
        if(!root)return 0;
        if(root->val==1)curr+='1';
        else curr+='0';
        if(!root->left&&!root->right){
            int ans=findNum(curr);
            curr.pop_back();
            return ans;
        }
        int ans = help(root->left,curr,i+1)+help(root->right,curr,i+1);
        curr.pop_back();
        return ans;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        string curr="";
        return help(root,curr,0);
    }
};