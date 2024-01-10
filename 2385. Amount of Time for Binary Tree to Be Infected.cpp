class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    TreeNode* makeMapping(TreeNode*root,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* begin = NULL;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->val == start){
                begin = node;
            }
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return begin;
    }

    int solve(TreeNode* root, TreeNode* start){
        queue<TreeNode*>q;
        q.push(start);
        unordered_set<TreeNode*>visited;
        visited.insert(start);
        int time = 0;
        for(auto i:mp){
            cout<<i.first->val<<" "<<i.second->val<<endl;
        }
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                if(node->left && visited.count(node->left) == 0){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && visited.count(node->right) == 0){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(mp.count(node) > 0 && visited.count(mp[node]) == 0){
                    visited.insert(mp[node]);
                    q.push(mp[node]);
                }
            }
            if(q.size() > 0){
                time++;
            }
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode*begin = makeMapping(root,start);
        return solve(root,begin);
    }
};