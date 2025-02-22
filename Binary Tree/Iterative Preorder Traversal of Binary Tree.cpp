// bcz stack is LIFO so we push right first then left so at top left is there to pop out and process
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);

            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return ans;
    }
};
