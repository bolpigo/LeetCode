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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		int n = num.size();
		return partition(num,0,n-1);
	}
	TreeNode *partition(vector<int> &num, int start, int end) {
		if(start > end) return NULL;
		int mid = (start+end)/2;
		TreeNode *root = new TreeNode(num[mid]);
		root->left = partition(num,start,mid-1);
		root->right = partition(num,mid+1,end);
		return root;
	}
};
