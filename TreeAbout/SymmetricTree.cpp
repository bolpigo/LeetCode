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
	bool isSymmetric(TreeNode *root) {
		return isSame(root, root);
	}
private:
	bool isSame(TreeNode *lhs, TreeNode *rhs) {
		if(!lhs && !rhs) return true;
		if(!lhs || !rhs) return false;
		return (lhs->val == rhs->val) && isSame(lhs->left,rhs->right) && isSame(lhs->right, rhs->left);
	}
};
