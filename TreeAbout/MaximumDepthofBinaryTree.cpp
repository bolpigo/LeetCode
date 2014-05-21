/**
* Definition for binary tree
* struct TreeNode {
*	int val;
*	TreeNode *left, *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
public:
	int maxDepth(TreeNode *root) {
		if(!root) return 0;
		if(!root->left && !root->right) return 1;
		int lhs = maxDepth(root->left);
		int rhs = maxDepth(root->right);
		return 1+(lhs > rhs ? lhs : rhs);
	}
};
