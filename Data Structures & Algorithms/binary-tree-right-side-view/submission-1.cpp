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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        stack<pair<TreeNode*, int>> nodes;
        vector<int>sol;
        sol.push_back(root->val);
        nodes.push({root,0});
        while(!nodes.empty()){
            auto [curr, lvl] = nodes.top();
            nodes.pop();
            if(curr->left){
                nodes.push({curr->left, lvl + 1});
                if(lvl + 1 >= sol.size() && !curr->right){
                    sol.push_back(curr->left->val);
                }
            }

            if(curr->right){
                nodes.push({curr->right, lvl + 1});
                if(lvl + 1 >= sol.size()){
                    sol.push_back(curr->right->val);
                }
            }
        }

        return sol;
    }
};
