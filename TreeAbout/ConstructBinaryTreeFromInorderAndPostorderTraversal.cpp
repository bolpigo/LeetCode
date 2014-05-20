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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int m = inorder.size(), n = postorder.size();
		return buildTree(inorder,0,m-1,postorder,0,n-1);
	}
private:
	TreeNode *buildTree(vector<int> &inorder,int st1, int end1, vector<int> &postorder, int st2, int end2) {
		if(st1>end1 || st2 > end2) reutn NULL;
		int val = postorder[end2];
		TreeNode *root = new TreeNode(val);
		int i;
		for(i=st1; i<=end1; ++i) {
			if(val==inorder[i]) break;
		}
		int len = i-st1;
		root->left = buildTree(inorder,st1,i-1,postorder,st2,st2+len-1);
		root->right = buildTree(inorder,i+1,end1,postorder, st2+len, end2-1);
		return root;
	}
};
