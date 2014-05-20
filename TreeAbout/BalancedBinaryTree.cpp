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
	bool isBalanced(TreeNode *root) {
		if(!root) return 0;
		int dif = distance(root->left)-distance(root->right);
		if(dif < -1 || dif > 1) return false;
		return isBalanced(root->left)&&isBalanced(root->right);
	}
private:
	int distance(TreeNode *root) {
		if(!root) return 0;
		int lhs = distance(root->left);
		int rhs = distance(root->right);
		return 1+(lhs>rhs?lhs:rhs);
	}
};
