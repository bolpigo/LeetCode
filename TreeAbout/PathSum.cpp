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
	bool hasPathSum(TreeNode *root, int sum) {
		if(!root) return false;
		if(!root->left && !root->right) {
			if(sum==root->val) return true;
			else return false;
		}
		bool lhs = hasPathSum(root->left, sum-root->val);
		if(lhs) return true;
		bool rhs = hasPathSum(root->right, sum-root->val);
		return rhs;
	}
};
