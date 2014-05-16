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
public:
	int sumNumbers(TreeNode *root) {
		int sum=0;
		dfs(sum,root,0);
		return sum;
	}
	void dfs(int &sum, TreeNode *root, int cursum) {
		if(root==NULL) return;
		if(!root->left && !root->right) sum+=cumsum*10+root->val;
		dfs(sum, root->left, cursum*10+root->val);
		dfs(sum, root->right, cursum*10+root->val);
	}
}
