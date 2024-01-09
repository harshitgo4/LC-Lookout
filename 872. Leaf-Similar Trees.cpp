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
    void helper(TreeNode* root1,vector<int> &ans)
    {
        if(root1==NULL)
        return ;
        helper(root1->left,ans);
        if(root1->left==NULL && root1->right==NULL)
        ans.push_back(root1->val);
        helper(root1->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL&&root2==NULL)
        return true;
        if(root1==NULL||root2==NULL)
        {
           return false;
        }
        bool res=true;
        vector<int> ans1;
        vector<int> ans2;
        helper(root1,ans1);
        helper(root2,ans2);
        if(ans1.size()==ans2.size())
        {
            int n=ans1.size();
            for(int i=0;i<n;i++)
            {
                if(ans1[i]!=ans2[i])
                {
                res=false;
                break;
                }
            }
        }
        else
        {
            res=false;
        }
        return res;
    }
};