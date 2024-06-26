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
    TreeNode* f(int l, int r){
        if(l>r)return nullptr;
        int median=(l+r)/2;
        TreeNode* cur=new TreeNode(arr[median]);
        cur->left=f(l,median-1);
        cur->right=f(median+1,r);
        return cur;
    }
    vector<int>arr;
    TreeNode* balanceBST(TreeNode* root) {
        f2(root);
        int n=arr.size();
        return f(0,n-1);
    }
    void f2(TreeNode* root){
        if(!root)return;
        f2(root->left);
        arr.push_back(root->val);
        f2(root->right);
    }
};