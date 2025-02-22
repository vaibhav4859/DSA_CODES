void helper(TreeNode* root, vector<int>& inorder, vector<int>& preorder, vector<int>& postorder) {
    if(root == NULL) return;
    preorder.push_back(root->data);
    helper(root->left, inorder, preorder, postorder);
    inorder.push_back(root->data);
    helper(root->right, inorder, preorder, postorder);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> inorder, preorder, postorder;
    helper(root, inorder, preorder, postorder);
    return {inorder, preorder, postorder};
}
