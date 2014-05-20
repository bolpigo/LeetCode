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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int m = preorder.size(),n=inorder.size();
		return buildTree(preorder,0,m-1,inorder,0,n-1);
	}
private:
	TreeNode *buildTree(vector<int> &preorder, int st1, int end1, vector<int> &inorder, int st2, int end2) {
		if(st1 > end1 || st2 > end2) return NULL;
		int val = preorder[st1];
		TreeNode *root = new TreeNode(val);
		int i;
		for(i=st2; i <= end2; ++i) {
			if(val == inorder[i]) break;
		}
		int len=i-st2;
		root->left = buildTree(preorder,st1+1,st1+len,inorder,st2,i-1);
		root->right = buildTree(preorder,st1+len+1,end1,inorder,i+1,end2);
		return root;
	}
};
