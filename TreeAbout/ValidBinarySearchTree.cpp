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
	bool isValidBST(TreeNode *root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}
	bool isValidBST(TreeNode *root, int min, int max) {
		if(!root) return true;
		if(root->val > min && root->val < max) {
			return isValidBST(root->left,min,root->val) && isValidBST(root->right,root->val,max);
		} else return false;
	}
};
