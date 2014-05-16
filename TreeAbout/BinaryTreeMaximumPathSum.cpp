/**
* Definition for binary tree
* struct TreeNode {
* 	int val;
*	TreeNode *left;
*	TreeNode *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
private:
	int maxSum=INT_MIN;
public:
	int maxPath(TreeNode *root) {
		if(!root) return 0;
		int lmax=0, rmax=0;
		int val=root->val;
		if(root->left) {
			lmax=maxPath(root->left);
			if(lmax>0)	val+=lmax;
		}
		if(root->right) {
			rmax=maxPath(root->right);
			if(rmax > 0) val+=rmax;
		}
		if(maxSum < val) maxSum=val;
		return max(root->val, max(root->val+lmax, root->val+rmax));
	}
	int maxPathSum(TreeNode *root) {
		if(!root) return 0;
		maxPath(root);
		return maxSum;
	}
};
