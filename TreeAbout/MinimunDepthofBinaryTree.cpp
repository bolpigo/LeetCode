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
	int minDepth(TreeNode *root) {
		if(!root) return;
		if(!root->left && !root->righ) return 1;
		int lhs = minDepth(root->left);
		int rhs = minDepth(root->right);
		if(0==lhs) return rhs+1;
		if(0==rhs) return lhs+1;
		return min(lhs+1,rhs+1);
	}
};
